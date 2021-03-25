#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QPixmap>
#include <QDebug>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    /* ------------------------------------------------------------------------------*/
    //      SETUP User Interface
    /* ------------------------------------------------------------------------------*/
    ui->setupUi(this);


    /* ------------------------------------------------------------------------------*/
    //      Start Timer for weather data update
    /* ------------------------------------------------------------------------------*/


    // Whenever an API call was made, send the weather info to updateWeatherUISlot, this updates the images
    QObject::connect(this, SIGNAL(updateWeatherUI(int, QString)),this, SLOT(updateWeatherUISlot(int, QString)));

    // This makes an API call
    manager = new QNetworkAccessManager();

    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            // Read API response
            QByteArray val = reply->readAll();

            // Make Json Document to Object
            QJsonDocument JsonDoc = QJsonDocument::fromJson(val);
            QJsonObject JsonObj = JsonDoc.object();

            // Get the "weather" branch out of the root json tree
            QJsonValue agentsArrayValue = JsonObj.value("weather");
            QJsonArray agentsArray = agentsArrayValue.toArray();

            // Return the current weather
            qDebug() << agentsArray[0].toObject().value("id").toInt();
            qDebug() << agentsArray[0].toObject().value("main").toString();
            qDebug() << agentsArray[0].toObject().value("description").toString();

            int weatherCode = agentsArray[0].toObject().value("id").toDouble();
            QString desc = agentsArray[0].toObject().value("description").toString();

            emit updateWeatherUI(weatherCode, desc);

        }
    );

    // Get weather directly after program start
    request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Apfeltrach&appid=d384c6a1b72e0adf71db8f11cf52f0db"));
    manager->get(request);

    // Get wather every x milliseconds
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWeather()));
    timer->start(30000);



    /* ------------------------------------------------------------------------------*/
    //      SETUP TCP Connection
    /* ------------------------------------------------------------------------------*/
    server = new QTcpServer();
    if(!server->listen(QHostAddress::Any, 9600))
    {
        qDebug()<<server->errorString();
        ui->connectionState->setText(server->errorString());
        return;
    }
    qDebug()<< "Listening on port 9600...";
    ui->connectionState->setText("No phone connected");
    ui->connectionState->setStyleSheet("QLabel { color : red; }");
    connect(server,&QTcpServer::newConnection,this,&MainWindow::server_New_Connect);


    /* ------------------------------------------------------------------------------*/
    //      SETUP Serial Connection
    /* ------------------------------------------------------------------------------*/

    bool arduino_available = false;
    QString portName;

    // Look for connected devices
    for(const QSerialPortInfo &serialPortInfo : QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier() << " Product ID: " << serialPortInfo.productIdentifier();
            if(serialPortInfo.vendorIdentifier() == 9025 && serialPortInfo.productIdentifier() == 66){
                portName = serialPortInfo.portName();
                arduino_available = true;
            }
        }
    }

    if(arduino_available){
        serial = new QSerialPort();
        serial->setPortName(portName);
        serial->setBaudRate(QSerialPort::Baud115200);
        serial->setDataBits(QSerialPort::Data8);
        serial->setParity(QSerialPort::NoParity);
        serial->setStopBits(QSerialPort::OneStop);
        serial->setFlowControl(QSerialPort::NoFlowControl);
        connect(serial,SIGNAL(readyRead()),this, SLOT(serialReceived()));
        if(!serial->open(QIODevice::ReadWrite)){
            qDebug() << serial->error();
            return;
        }else{
            serial->write("<0:0>"); // Initialize
        }
    }else{
        qDebug() << "Arduino not found";
    }


}

MainWindow::~MainWindow()
{
    server->close();
    server->deleteLater();
    delete ui;
}

/* ------------------------------------------------------------------------------*/
//      TCP Connection Established
/* ------------------------------------------------------------------------------*/

void MainWindow::server_New_Connect()
{
    //Getting Client Connection
    socket = server->nextPendingConnection();
    //Connect the signal slot of the QTcpSocket to read the new data
    QObject::connect(socket, &QTcpSocket::readyRead, this, &MainWindow::socket_Read_Data);
    QObject::connect(socket, &QTcpSocket::disconnected, this, &MainWindow::socket_Disconnected);
    //Send key enablement

    qDebug() << "A Client connect!";
    ui->connectionState->setText("Phone connected");
    ui->connectionState->setStyleSheet("QLabel { color : green; }");

    // Send current state to mobile application
    socket->write(makeSendable(1,ui->slider_light->value()));
    socket->write(makeSendable(9,ui->shutterProgress->value()));

    if(ui->btn_shuttersDown->isEnabled() == false){
        socket->write(makeSendable(2,1));
        socket->flush();
    }else if(ui->btn_shuttersUp->isEnabled() == false){
        socket->write(makeSendable(2,0));
        socket->flush();
    }

    if(ui->btn_tilt->text() == "Tilt"){
        socket->write(makeSendable(3,0));
        socket->flush();
    }else{
        socket->write(makeSendable(3,1));
        socket->flush();
    }
}


/* ------------------------------------------------------------------------------*/
//      Read Socket Data
/* ------------------------------------------------------------------------------*/
void MainWindow::socket_Read_Data()
{
    QByteArray buffer;
    //Read Buffer Data
    buffer = socket->readAll();
    if(!buffer.isEmpty())
    {
        QString str = buffer;

        QString msg;

        bool startMessage = false;

        for(int i=0;i<str.length();i++){
            if(str.at(i) == '<'){
                startMessage = true;
            }
            if(!(str.at(i) == '>') && str.at(i) != '<' && startMessage==true){
                msg.append(str.at(i));
            }else if(str.at(i) == '>')
            {
                if(!msg.isEmpty() && msg.contains(':'))
                {
                    QStringList keypair = msg.split(":");

                    bool *errorPointer = nullptr;
                    int device = keypair.at(0).toInt(errorPointer,2);
                    int value = keypair.at(1).toInt(errorPointer,2);

                    qDebug() << "TCP in: Device "+ QString::number(device) + " Value: "+ QString::number(value);

                    switch(device){
                        case 1:
                            if(value==0){
                                QByteArray message = makeSendable(1,0);
                                serial->write(message);

                                ui->btn_lightOff->setDisabled(true);
                                ui->btn_lightOn->setDisabled(false);
                            }else if(value==255){
                                QByteArray message = makeSendable(1,255);
                                serial->write(message);

                                ui->btn_lightOff->setDisabled(false);
                                ui->btn_lightOn->setDisabled(true);
                            }else
                            {
                                ui->btn_lightOff->setDisabled(false);
                                ui->btn_lightOn->setDisabled(false);
                            }
                            ui->slider_light->setValue(value);
                            break;

                        case 2:
                            if(value==0){
                                QByteArray message = makeSendable(2,0);
                                serial->write(message);

                                ui->btn_shuttersUp->setDisabled(true);
                                ui->btn_shuttersDown->setDisabled(false);
                            }else if(value==1){
                                QByteArray message = makeSendable(2,1);
                                serial->write(message);

                                ui->btn_shuttersUp->setDisabled(false);
                                ui->btn_shuttersDown->setDisabled(true);
                            }
                            break;

                        case 3:
                            if(value==0){
                                QByteArray message = makeSendable(3,1);
                                serial->write(message);

                                ui->btn_tilt->setText("Tilt");
                            }else if(value==1){
                                QByteArray message = makeSendable(3,0);
                                serial->write(message);

                                ui->btn_tilt->setText("Close");
                            }
                            break;
                        case 4:
                            QByteArray message = makeSendable(4,value);
                            serial->write(message);
                            ui->slider_temp->setValue(value);
                        break;
                    }
                }
                msg.clear();
                startMessage = false;
            }
        }
    }
}

/* ------------------------------------------------------------------------------*/
//      Socket Disconnected
/* ------------------------------------------------------------------------------*/
void MainWindow::socket_Disconnected()
{
    //Send button failure
    ui->connectionState->setText("No phone connected");
    ui->connectionState->setStyleSheet("QLabel { color : red; }");
}


/* ------------------------------------------------------------------------------*/
//      Read Serial Data
/* ------------------------------------------------------------------------------*/
void MainWindow::serialReceived()
{
    QString recv = serial->readAll();
    QString msg;

    bool startMessage = false;

    for(int i=0;i<recv.length();i++){
        if(recv.at(i) == '<'){
            startMessage = true;
        }
        if(!(recv.at(i) == '>') && recv.at(i) != '<' && startMessage==true){
            msg.append(recv.at(i));
        }else if(recv.at(i) == '>')
        {
            if(!msg.isEmpty() && msg.contains(':'))
            {
                QStringList keypair = msg.split(":");
                qDebug() << "Serial in: Device "+ keypair.at(0)+ " Value: "+ keypair.at(1);

                int device = keypair.at(0).toInt();
                QString value = keypair.at(1);

                switch(device){
                case 5:
                    ui->display_temp->setText(value+" °C");
                    break;
                case 6:
                    ui->display_humidity->setText(value+" %");
                    break;
                case 7:
                    ui->display_brightness->setText(value);
                    break;
                case 8:
                    ui->display_airpressure->setText(value+" hPa");
                    break;
                case 9:
                    if(value == 0){
                        ui->btn_shuttersUp->setEnabled(false);
                        ui->btn_shuttersDown->setEnabled(true);
                    }else if(value == 2048){
                        ui->btn_shuttersUp->setEnabled(true);
                        ui->btn_shuttersDown->setEnabled(false);
                    }
                    ui->shutterProgress->setValue(value.toInt());
                    break;
                }


                if(socket->state() == QAbstractSocket::ConnectedState)
                {
                    QByteArray message = makeSendable(device,keypair.at(1).toFloat());
                    socket->write(message);
                    socket->flush();
                }
            }
            msg.clear();
            startMessage = false;
        }
    }

}


/* ------------------------------------------------------------------------------*/
//              User Interface
/* ------------------------------------------------------------------------------*/

void MainWindow::on_btn_lightOff_clicked()
{
    QByteArray message = makeSendable(1,0);

    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(message);
        socket->flush();
    }
    if(serial->isOpen()){
        serial->write(message);
    }

    ui->btn_lightOff->setEnabled(false);
    ui->btn_lightOn->setEnabled(true);
    ui->slider_light->setValue(0);
}

void MainWindow::on_btn_lightOn_clicked()
{
    QByteArray message = makeSendable(1,255);

    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(message);
        socket->flush();
    }
    serial->write(message);


    ui->btn_lightOff->setEnabled(true);
    ui->btn_lightOn->setEnabled(false);
    ui->slider_light->setValue(255);
}

void MainWindow::on_slider_light_valueChanged(int i)
{
    QByteArray message = makeSendable(1,i);

    if(socket->state() == QAbstractSocket::ConnectedState)
    { 
        socket->write(message);
        socket->flush();
    }
    if(serial->isOpen()){
        serial->write(message);
    }

    if(i == 255){
        ui->btn_lightOn->setEnabled(false);
    }else if(i == 0){
        ui->btn_lightOff->setEnabled(false);
    }else{
        ui->btn_lightOn->setEnabled(true);
        ui->btn_lightOff->setEnabled(true);
    }
}

void MainWindow::on_btn_shuttersUp_clicked()
{
    QByteArray message = makeSendable(2,0);

    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(message);
        socket->flush();
    }
    if(serial->isOpen()){
        serial->write(message);
    }

    ui->btn_shuttersUp->setEnabled(false);
    ui->btn_shuttersDown->setEnabled(true);
}

void MainWindow::on_btn_shuttersDown_clicked()
{
    QByteArray message = makeSendable(2,1);

    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(message);
        socket->flush();
    }
    if(serial->isOpen()){
        serial->write(message);
    }

    ui->btn_shuttersUp->setEnabled(true);
    ui->btn_shuttersDown->setEnabled(false);
}

void MainWindow::on_btn_tilt_clicked()
{


    if(ui->btn_tilt->text() == "Tilt"){
        QByteArray message = makeSendable(3,1);

        if(socket->state() == QAbstractSocket::ConnectedState)
        {
            socket->write(message);
            socket->flush();
        }

        qDebug() << "Opening: " << message;
        if(serial->isOpen()){
            serial->write(message);
            ui->btn_tilt->setText("Close");
        }

    }else{


        QByteArray message = makeSendable(3,0);

        if(socket->state() == QAbstractSocket::ConnectedState)
        {
            socket->write(message);
            socket->flush();
        }
        qDebug() << "Closing: " << message;
        if(serial->isOpen()){
            serial->write(message);
            ui->btn_tilt->setText("Tilt");
        }

    }

}



void MainWindow::on_slider_temp_valueChanged(int i)
{
    QByteArray message = makeSendable(4,i);
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        socket->write(message);
        socket->flush();
    }
    if(serial->isOpen()){
        serial->write(message);
    }

}


QByteArray MainWindow::makeSendable(int device, int value){
    QString startChar = "<";
    QString endChar   = ">";
    QString seperator = ":";

    QString str_device = QString::number(device);
    QString str_value  = QString::number(value);

    return startChar.toUtf8()+str_device.toUtf8()+seperator.toUtf8()+str_value.toUtf8()+endChar.toUtf8();
}



void MainWindow::updateWeather()
{
    qDebug() << "Updating weather data...";
    request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Apfeltrach&appid=d384c6a1b72e0adf71db8f11cf52f0db"));
    manager->get(request);
}

void MainWindow::updateWeatherUISlot(int weatherCode, QString desc){
    qDebug() << "received weatherCode: " << weatherCode;

    QString fileExtension = "200.png";

    if(weatherCode >= 200 &&  weatherCode < 300){
        fileExtension = "200.png";
    }else if(weatherCode >= 300 && weatherCode < 400){
        fileExtension = "300.png";
    }else if(weatherCode >= 500 && weatherCode <= 504){
        fileExtension = "500-504.png";
    }else if(weatherCode == 511){
        fileExtension = "511.png";
    }else if(weatherCode >= 520 && weatherCode <= 531){
        fileExtension = "520-531.png";
    }else if(weatherCode == 600){
        fileExtension = "600.png";
    }else if(weatherCode == 700){
        fileExtension = "700.png";
    }else if(weatherCode == 800){
        fileExtension = "800day.png";
    }else if(weatherCode == 801){
        fileExtension = "801day.png";
    }else if(weatherCode == 802){
        fileExtension = "802.png";
    }else if(weatherCode == 803){
        fileExtension = "803.png";
    }else if(weatherCode == 804){
        fileExtension = "804.png";
    }



    QPixmap pm(":/img/res/img/"+fileExtension);
    ui->weatherImage->setPixmap(pm);
    ui->weatherDesc->setText(desc);
}

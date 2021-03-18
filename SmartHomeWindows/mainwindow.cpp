#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPortInfo>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    /* ------------------------------------------------------------------------------*/
    //      SETUP User Interface
    /* ------------------------------------------------------------------------------*/
    ui->setupUi(this);

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
            if(serialPortInfo.vendorIdentifier() == 9025 && serialPortInfo.productIdentifier() == 67){
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
    //socket->write("CONNECTED TO SMART HOME SYSTEM");
    //socket->flush();
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

        /*
        // Check if Signal has the right format
        if(str.startsWith('<') && str.endsWith('>') && str.contains(':'))
        {
            str = str.remove('<');
            str = str.remove('>');
            QStringList receivedMessage = str.split(':');
            QString str_device = receivedMessage.at(0);
            QString str_value = receivedMessage.at(1);
            qDebug() << "Str Device: "+str_device + " Str Value: "+str_value;

            bool *errorPointer = nullptr;
            int device = str_device.toInt(errorPointer,2);
            int value = str_value.toInt(errorPointer,2);
            qDebug() << "Device: "+QString::number(device)+ " Value: "+QString::number(value);

            switch(device){
                case 1:
                    if(value==0){
                        ui->btn_lightOff->setDisabled(true);
                        ui->btn_lightOn->setDisabled(false);
                        serial->write("<1:0>");
                    }else if(value==255){
                        ui->btn_lightOff->setDisabled(false);
                        ui->btn_lightOn->setDisabled(true);
                        serial->write("<1:255>");
                    }else
                    {
                        ui->btn_lightOff->setDisabled(false);
                        ui->btn_lightOn->setDisabled(false);
                    }
                    ui->slider_light->setValue(value);
                    break;

                case 2:
                    if(value==0){
                        ui->btn_shuttersUp->setDisabled(true);
                        ui->btn_shuttersDown->setDisabled(false);
                        serial->write("<2:0>");
                    }else if(value==1){
                        ui->btn_shuttersUp->setDisabled(false);
                        ui->btn_shuttersDown->setDisabled(true);
                        serial->write("<2:1>");
                    }
                    break;

                case 3:
                    if(value==0){
                        ui->btn_tilt->setText("Tilt");
                        serial->write("<3:1>");
                    }else if(value==1){
                        ui->btn_tilt->setText("Close");
                        serial->write("<3:0>");
                    }
                    break;
                case 4:
                    ui->slider_temp->setValue(value);
                    QByteArray message;
                    QString device = "4";
                    QString value = str_value;
                    QString message_str =device+":"+str_value;
                    message = message_str.toUtf8();
                    serial->write(message);
                break;
            }
            qDebug() << "Device: "+QString::number(device)+ " Value: "+QString::number(value);
            }else{
                qDebug() << "Wrong format received, returning... Message:" << str;
                return;
            }
        */
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
                    ui->display_temp->setText(value+"°C");
                    break;
                case 6:
                    ui->display_humidity->setText(value+"%");
                    break;
                case 7:
                    ui->display_brightness->setText(value);
                    break;
                case 8:
                    ui->display_airpressure->setText(value);
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
    serial->write(message);

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
    serial->write(message);

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
    serial->write(message);

    ui->btn_shuttersUp->setEnabled(true);
    ui->btn_shuttersDown->setEnabled(false);
}

void MainWindow::on_btn_tilt_clicked()
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        if(ui->btn_tilt->text() == "Tilt"){
            QByteArray message = makeSendable(3,1);
            socket->write(message);
            socket->flush();
            serial->write(message);
            ui->btn_tilt->setText("Close");
        }else{
            QByteArray message = makeSendable(3,0);
            socket->write(message);
            socket->flush();
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
    serial->write(message);

}


QByteArray MainWindow::makeSendable(int device, int value){
    QString startChar = "<";
    QString endChar   = ">";
    QString seperator = ":";

    QString str_device = QString::number(device);
    QString str_value  = QString::number(value);

    return startChar.toUtf8()+str_device.toUtf8()+seperator.toUtf8()+str_value.toUtf8()+endChar.toUtf8();
}



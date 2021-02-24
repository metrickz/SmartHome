#include "tcpsocket.h"

tcpSocket::tcpSocket(QObject *parent) :
    QObject(parent)
{
}


void tcpSocket::doConnect(){
    // Create new Socket
    socket = new QTcpSocket(this);

    // Connect Signal and Slots
    connect(socket, SIGNAL(connected()),this, SLOT(connected()));
    connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
    connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
    connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));

    qDebug() << "CONNECTING";

    // Connect to Host and wait for established connection
    socket->connectToHost("127.0.0.1", 1337);
    if(!socket->waitForConnected(45000))
    {
        qDebug() << "Error: " << socket->errorString();
    }
}


void tcpSocket::connected()
{
    qDebug() << "Connection Established. Success...";

    // Write Message
    socket->write("SmartHome System");
}

void tcpSocket::disconnected()
{
    qDebug() << "Disconnected";
}

void tcpSocket::bytesWritten(qint64 bytes)
{
    qDebug() << bytes << " bytes written...";
}

void tcpSocket::readyRead()
{
    qDebug() << "reading...";

    // read the data from the socket
    qDebug() << socket->readAll();
}

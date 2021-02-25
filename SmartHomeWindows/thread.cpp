#include "thread.h"

Thread::Thread(int ID, QObject *parent) : QThread(parent)
{
    this->socketDescriptor = ID;
}

void Thread::run()
{
    qDebug() << socketDescriptor << " Starting Thread";
    socket = new QTcpSocket();

    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()), Qt::DirectConnection);

    qDebug() << socketDescriptor << " Client connected";

    exec();

}

void Thread::sendData()
{
    socket->write("Data test");
}

void Thread::readyRead()
{
    QByteArray data = socket->readAll();
    qDebug() << socketDescriptor << " Data in: " << data;
    socket->write(data);
}

void Thread::disconnected()
{
    qDebug() << socketDescriptor << " Client disconnected";
    socket->deleteLater();
    exit(0);
}

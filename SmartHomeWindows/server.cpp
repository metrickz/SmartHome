#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent)
{

}

void Server::startServer()
{
    if(!this->listen(QHostAddress::Any,1337))
    {
       qDebug() << "Error starting Server...";
    }
    else
    {
        qDebug() << "Listening...";
    }
}

void Server::incomingConnection(qintptr  socketDescriptor)
{
    qDebug() << socketDescriptor << " Connecting...";
    Thread *thread = new Thread(socketDescriptor,this);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}

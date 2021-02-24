#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>
#include <QAbstractSocket> // test


class tcpSocket : public QObject
{  
    Q_OBJECT

public:
    explicit tcpSocket(QObject *parent = 0);
    void doConnect();

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();

private:
    QTcpSocket *socket;
};

#endif // TCPSOCKET_H

#include "tcpsocket.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    tcpSocket socket;
    w.show();
    socket.doConnect();
    return a.exec();
}

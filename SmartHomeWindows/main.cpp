#include "tcpsocket.h"
#include "server.h"
#include "mainwindow.h"



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Server server;
    server.startServer();
    w.show();
    return a.exec();
}

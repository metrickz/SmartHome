#include "mainwindow.h"
#include "weatherupdatetimer.h"



#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    WeatherUpdateTimer timer;


    w.show();
    return a.exec();
}

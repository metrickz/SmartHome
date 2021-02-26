#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>
#include <QtDebug>

QSerialPort *serial;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //serial->setPortName("COM3");
    //serial->setBaudRate(QSerialPort::Baud9600);
    //serial->setDataBits(QSerialPort::Data8);
    //serial->setParity(QSerialPort::NoParity);
    //serial->setStopBits(QSerialPort::OneStop);
    //serial->setFlowControl(QSerialPort::NoFlowControl);
/*
    connect(serial,SIGNAL(readyRead()),this, SLOT(serialReceived()));

    if (serial->open(QIODevice::ReadWrite))
    {
        //Connected
    }
    else
    {
        //Open error
    }
*/


}


void MainWindow::serialReceived()
{
    //qDebug() << serial->readAll();
}

MainWindow::~MainWindow()
{
    delete ui;
    //serial->close();
}


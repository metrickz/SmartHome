#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "server.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(Server::Server,)
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_btn_lightOff_clicked()
{

}

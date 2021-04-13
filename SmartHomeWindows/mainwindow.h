#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSerialPort>

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QNetworkAccessManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void server_New_Connect();
    void socket_Read_Data();
    void socket_Disconnected();

    void serialReceived();

    void on_btn_lightOn_clicked();
    void on_btn_lightOff_clicked();
    void on_btn_shuttersUp_clicked();
    void on_btn_shuttersDown_clicked();
    void on_btn_tilt_clicked();
    void on_slider_light_valueChanged(int value);
    void on_slider_temp_valueChanged(int value);

    void updateWeather();
    void updateWeatherUISlot(int weatherCode, QString desc, int sunrise, int sunset);

signals:
    void updateWeatherUI(int weatherCode, QString desc, int sunrise, int sunset);



private:
    Ui::MainWindow *ui;
    QTcpServer* server;
    QTcpSocket* socket;

    QSerialPort *serial;
    QByteArray makeSendable(int device, int value);

    //WeatherUpdateTimer *timer;

    QNetworkAccessManager *manager;
    QNetworkRequest request;


};
#endif // MAINWINDOW_H

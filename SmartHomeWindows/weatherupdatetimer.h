#ifndef WEATHERUPDATETIMER_H
#define WEATHERUPDATETIMER_H

#include <QTimer>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

class QNetworkAccessManager;

class WeatherUpdateTimer : public QObject
{
    Q_OBJECT
public:
    WeatherUpdateTimer();
    QTimer *timer;


public slots:
    void TimerSlot();

private:
    QNetworkAccessManager *manager;
    QNetworkRequest request;


};

#endif // WEATHERUPDATETIMER_H




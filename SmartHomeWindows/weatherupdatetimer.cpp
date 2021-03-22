#include "weatherupdatetimer.h"
#include <QDebug>


WeatherUpdateTimer::WeatherUpdateTimer()
{

    manager = new QNetworkAccessManager();
        QObject::connect(manager, &QNetworkAccessManager::finished,
            this, [=](QNetworkReply *reply) {
                if (reply->error()) {
                    qDebug() << reply->errorString();
                    return;
                }

                QString answer = reply->readAll();

                qDebug() << answer;
            }
        );
    timer = new QTimer(this);


    // setup signal and slot
    connect(timer, SIGNAL(timeout()),
          this, SLOT(TimerSlot()));

    // Set Timer value in ms
    timer->start(15000);


}


void WeatherUpdateTimer::TimerSlot()
{
    // http://api.openweathermap.org/data/2.5/weather?q=Apfeltrach&appid=d384c6a1b72e0adf71db8f11cf52f0db

    qDebug() << "Updating weather data...";
    request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Apfeltrach&appid=d384c6a1b72e0adf71db8f11cf52f0db"));
    manager->get(request);

}


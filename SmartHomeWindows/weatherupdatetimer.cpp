#include "weatherupdatetimer.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>



WeatherUpdateTimer::WeatherUpdateTimer()
{

    manager = new QNetworkAccessManager();

    QObject::connect(manager, &QNetworkAccessManager::finished,
        this, [=](QNetworkReply *reply) {
            if (reply->error()) {
                qDebug() << reply->errorString();
                return;
            }

            // Read API response
            QByteArray val = reply->readAll();

            // Make Json Document to Object
            QJsonDocument JsonDoc = QJsonDocument::fromJson(val);
            QJsonObject JsonObj = JsonDoc.object();

            // Get the "weather" branch out of the root json tree
            QJsonValue agentsArrayValue = JsonObj.value("weather");
            QJsonArray agentsArray = agentsArrayValue.toArray();

            // Return the current weather
            qDebug() << agentsArray[0].toObject().value("id").toInt();
            qDebug() << agentsArray[0].toObject().value("main").toString();
            qDebug() << agentsArray[0].toObject().value("description").toString();

            int weatherCode = agentsArray[0].toObject().value("id").toDouble();
            QString desc = agentsArray[0].toObject().value("description").toString();

            emit updateWeatherImage(weatherCode, desc);


        }
    );


    // Get weather data instantaneously after starting the programm
    qDebug() << "Updating weather data...";
    request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Apfeltrach&appid=d384c6a1b72e0adf71db8f11cf52f0db"));
    manager->get(request);

    // Set timer and get data every minute
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()),
          this, SLOT(TimerSlot()));

    timer->start(10000);


}


void WeatherUpdateTimer::TimerSlot()
{
    // http://api.openweathermap.org/data/2.5/weather?q=Apfeltrach&appid=d384c6a1b72e0adf71db8f11cf52f0db

    qDebug() << "Updating weather data...";
    request.setUrl(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Apfeltrach&appid=d384c6a1b72e0adf71db8f11cf52f0db"));
    manager->get(request);

}



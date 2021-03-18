/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_lightOn;
    QSlider *slider_light;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btn_shuttersUp;
    QPushButton *btn_shuttersDown;
    QLabel *label_4;
    QPushButton *btn_tilt;
    QLabel *label_5;
    QSlider *slider_temp;
    QLabel *label_6;
    QLabel *label_7;
    QCalendarWidget *calendarWidget;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *connectionState;
    QLabel *display_temp;
    QLabel *display_humidity;
    QLabel *display_brightness;
    QLabel *display_airpressure;
    QPushButton *btn_lightOff;
    QProgressBar *shutterProgress;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(611, 412);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btn_lightOn = new QPushButton(centralwidget);
        btn_lightOn->setObjectName(QStringLiteral("btn_lightOn"));
        btn_lightOn->setGeometry(QRect(160, 40, 51, 31));
        slider_light = new QSlider(centralwidget);
        slider_light->setObjectName(QStringLiteral("slider_light"));
        slider_light->setGeometry(QRect(50, 80, 160, 16));
        slider_light->setMaximum(255);
        slider_light->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 10, 31, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 51, 21));
        btn_shuttersUp = new QPushButton(centralwidget);
        btn_shuttersUp->setObjectName(QStringLiteral("btn_shuttersUp"));
        btn_shuttersUp->setGeometry(QRect(60, 140, 71, 51));
        btn_shuttersDown = new QPushButton(centralwidget);
        btn_shuttersDown->setObjectName(QStringLiteral("btn_shuttersDown"));
        btn_shuttersDown->setGeometry(QRect(60, 190, 71, 51));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 240, 71, 21));
        btn_tilt = new QPushButton(centralwidget);
        btn_tilt->setObjectName(QStringLiteral("btn_tilt"));
        btn_tilt->setGeometry(QRect(60, 270, 71, 51));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 330, 71, 21));
        slider_temp = new QSlider(centralwidget);
        slider_temp->setObjectName(QStringLiteral("slider_temp"));
        slider_temp->setGeometry(QRect(40, 360, 160, 16));
        slider_temp->setMaximum(255);
        slider_temp->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 370, 21, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 370, 21, 21));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(310, 10, 281, 181));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(310, 250, 111, 21));
        QFont font;
        font.setPointSize(14);
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 320, 111, 21));
        label_9->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(310, 220, 111, 21));
        label_10->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(310, 280, 111, 31));
        label_11->setFont(font);
        connectionState = new QLabel(centralwidget);
        connectionState->setObjectName(QStringLiteral("connectionState"));
        connectionState->setGeometry(QRect(480, 370, 231, 21));
        QFont font1;
        font1.setPointSize(8);
        connectionState->setFont(font1);
        display_temp = new QLabel(centralwidget);
        display_temp->setObjectName(QStringLiteral("display_temp"));
        display_temp->setGeometry(QRect(460, 220, 111, 21));
        display_temp->setFont(font);
        display_humidity = new QLabel(centralwidget);
        display_humidity->setObjectName(QStringLiteral("display_humidity"));
        display_humidity->setGeometry(QRect(460, 250, 111, 21));
        display_humidity->setFont(font);
        display_brightness = new QLabel(centralwidget);
        display_brightness->setObjectName(QStringLiteral("display_brightness"));
        display_brightness->setGeometry(QRect(460, 280, 111, 31));
        display_brightness->setFont(font);
        display_brightness->setStyleSheet(QStringLiteral(""));
        display_airpressure = new QLabel(centralwidget);
        display_airpressure->setObjectName(QStringLiteral("display_airpressure"));
        display_airpressure->setGeometry(QRect(460, 320, 111, 21));
        display_airpressure->setFont(font);
        btn_lightOff = new QPushButton(centralwidget);
        btn_lightOff->setObjectName(QStringLiteral("btn_lightOff"));
        btn_lightOff->setGeometry(QRect(50, 40, 51, 31));
        btn_lightOff->setStyleSheet(QStringLiteral(""));
        shutterProgress = new QProgressBar(centralwidget);
        shutterProgress->setObjectName(QStringLiteral("shutterProgress"));
        shutterProgress->setGeometry(QRect(150, 140, 91, 101));
        shutterProgress->setStyleSheet(QLatin1String("QProgressBar::chunk {background-color: rgb(98, 98, 98);}\n"
""));
        shutterProgress->setMaximum(2048);
        shutterProgress->setValue(0);
        shutterProgress->setOrientation(Qt::Vertical);
        shutterProgress->setInvertedAppearance(true);
        shutterProgress->setTextDirection(QProgressBar::TopToBottom);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Obis Smart Home Control System", Q_NULLPTR));
        btn_lightOn->setText(QApplication::translate("MainWindow", "ON", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Light", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Shutters", Q_NULLPTR));
        btn_shuttersUp->setText(QApplication::translate("MainWindow", "UP", Q_NULLPTR));
        btn_shuttersDown->setText(QApplication::translate("MainWindow", "DOWN", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Tilt Window", Q_NULLPTR));
        btn_tilt->setText(QApplication::translate("MainWindow", "Tilt", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Temperature", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "20\302\260", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "28\302\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Humidity", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Air pressure", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Temperature", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Brightness", Q_NULLPTR));
        connectionState->setText(QApplication::translate("MainWindow", "No phone connected", Q_NULLPTR));
        display_temp->setText(QString());
        display_humidity->setText(QString());
        display_brightness->setText(QString());
        display_airpressure->setText(QString());
        btn_lightOff->setText(QApplication::translate("MainWindow", "OFF", Q_NULLPTR));
        shutterProgress->setFormat(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

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
    QLabel *weatherImage;
    QLabel *weatherDesc;
    QLabel *PID_value_text;
    QLabel *display_PIDvalue;
    QLabel *label_12;
    QLabel *lbl_Sunrise;
    QLabel *lbl_Sunset;
    QLabel *lbl_showSunrise;
    QLabel *lbl_showSunset;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(844, 426);
        MainWindow->setStyleSheet(QLatin1String("color: rgb(245, 245, 245);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        btn_lightOn = new QPushButton(centralwidget);
        btn_lightOn->setObjectName(QStringLiteral("btn_lightOn"));
        btn_lightOn->setGeometry(QRect(160, 40, 51, 31));
        btn_lightOn->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 0px;\n"
"border-radius: 50px;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-radius: 20px;\n"
"}"));
        slider_light = new QSlider(centralwidget);
        slider_light->setObjectName(QStringLiteral("slider_light"));
        slider_light->setGeometry(QRect(50, 80, 160, 16));
        slider_light->setStyleSheet(QLatin1String("\n"
"QSlider::handle:horizontal {\n"
"	background-color: rgb(98, 0, 238);\n"
"}"));
        slider_light->setMaximum(255);
        slider_light->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 10, 51, 21));
        label_2->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 101, 21));
        label_3->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        btn_shuttersUp = new QPushButton(centralwidget);
        btn_shuttersUp->setObjectName(QStringLiteral("btn_shuttersUp"));
        btn_shuttersUp->setGeometry(QRect(60, 140, 71, 51));
        btn_shuttersUp->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 0px;\n"
"border-radius: 50px;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-radius: 20px;\n"
"}"));
        btn_shuttersDown = new QPushButton(centralwidget);
        btn_shuttersDown->setObjectName(QStringLiteral("btn_shuttersDown"));
        btn_shuttersDown->setGeometry(QRect(60, 190, 71, 51));
        btn_shuttersDown->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 0px;\n"
"border-radius: 50px;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-radius: 20px;\n"
"}"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 240, 141, 21));
        label_4->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        btn_tilt = new QPushButton(centralwidget);
        btn_tilt->setObjectName(QStringLiteral("btn_tilt"));
        btn_tilt->setGeometry(QRect(60, 270, 71, 51));
        btn_tilt->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 0px;\n"
"border-radius: 50px;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-radius: 20px;\n"
"}"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 330, 121, 21));
        label_5->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        slider_temp = new QSlider(centralwidget);
        slider_temp->setObjectName(QStringLiteral("slider_temp"));
        slider_temp->setGeometry(QRect(40, 360, 160, 16));
        slider_temp->setStyleSheet(QLatin1String("\n"
"QSlider::handle:horizontal {\n"
"	background-color: rgb(98, 0, 238);\n"
"}"));
        slider_temp->setMaximum(255);
        slider_temp->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 370, 21, 21));
        label_6->setStyleSheet(QStringLiteral("color: rgb(40, 40, 40);"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(190, 370, 21, 21));
        label_7->setStyleSheet(QStringLiteral("color: rgb(40, 40, 40);"));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(310, 10, 281, 181));
        calendarWidget->setStyleSheet(QStringLiteral("color: rgb(97, 97, 97);"));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(310, 250, 111, 21));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(12);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        label_8->setFont(font);
        label_8->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(310, 320, 111, 21));
        label_9->setFont(font);
        label_9->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(310, 220, 111, 21));
        label_10->setFont(font);
        label_10->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(310, 280, 111, 31));
        label_11->setFont(font);
        label_11->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        connectionState = new QLabel(centralwidget);
        connectionState->setObjectName(QStringLiteral("connectionState"));
        connectionState->setGeometry(QRect(310, 380, 231, 21));
        QFont font1;
        font1.setPointSize(8);
        connectionState->setFont(font1);
        display_temp = new QLabel(centralwidget);
        display_temp->setObjectName(QStringLiteral("display_temp"));
        display_temp->setGeometry(QRect(460, 220, 111, 21));
        display_temp->setFont(font);
        display_temp->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        display_humidity = new QLabel(centralwidget);
        display_humidity->setObjectName(QStringLiteral("display_humidity"));
        display_humidity->setGeometry(QRect(460, 250, 111, 21));
        display_humidity->setFont(font);
        display_humidity->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        display_brightness = new QLabel(centralwidget);
        display_brightness->setObjectName(QStringLiteral("display_brightness"));
        display_brightness->setGeometry(QRect(460, 280, 111, 31));
        display_brightness->setFont(font);
        display_brightness->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        display_airpressure = new QLabel(centralwidget);
        display_airpressure->setObjectName(QStringLiteral("display_airpressure"));
        display_airpressure->setGeometry(QRect(460, 320, 111, 21));
        display_airpressure->setFont(font);
        display_airpressure->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        btn_lightOff = new QPushButton(centralwidget);
        btn_lightOff->setObjectName(QStringLiteral("btn_lightOff"));
        btn_lightOff->setGeometry(QRect(50, 40, 51, 31));
        btn_lightOff->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-style: solid;\n"
"border-width: 0px;\n"
"border-radius: 50px;\n"
"}\n"
"QPushButton:pressed{\n"
"background-color: rgb(98, 0, 238);\n"
"color: rgb(255, 255, 255);\n"
"border-width: 1px;\n"
"border-radius: 20px;\n"
"}"));
        shutterProgress = new QProgressBar(centralwidget);
        shutterProgress->setObjectName(QStringLiteral("shutterProgress"));
        shutterProgress->setGeometry(QRect(150, 140, 91, 101));
        shutterProgress->setStyleSheet(QStringLiteral("QProgressBar::chunk {background-color: rgb(98, 0, 238);}"));
        shutterProgress->setMaximum(2048);
        shutterProgress->setValue(0);
        shutterProgress->setOrientation(Qt::Vertical);
        shutterProgress->setInvertedAppearance(true);
        shutterProgress->setTextDirection(QProgressBar::TopToBottom);
        weatherImage = new QLabel(centralwidget);
        weatherImage->setObjectName(QStringLiteral("weatherImage"));
        weatherImage->setGeometry(QRect(660, 40, 101, 71));
        weatherDesc = new QLabel(centralwidget);
        weatherDesc->setObjectName(QStringLiteral("weatherDesc"));
        weatherDesc->setGeometry(QRect(610, 110, 201, 21));
        weatherDesc->setFont(font);
        weatherDesc->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        weatherDesc->setAlignment(Qt::AlignCenter);
        PID_value_text = new QLabel(centralwidget);
        PID_value_text->setObjectName(QStringLiteral("PID_value_text"));
        PID_value_text->setGeometry(QRect(310, 350, 111, 21));
        PID_value_text->setFont(font);
        PID_value_text->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        display_PIDvalue = new QLabel(centralwidget);
        display_PIDvalue->setObjectName(QStringLiteral("display_PIDvalue"));
        display_PIDvalue->setGeometry(QRect(460, 350, 111, 21));
        display_PIDvalue->setFont(font);
        display_PIDvalue->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(610, 10, 151, 21));
        label_12->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        lbl_Sunrise = new QLabel(centralwidget);
        lbl_Sunrise->setObjectName(QStringLiteral("lbl_Sunrise"));
        lbl_Sunrise->setGeometry(QRect(620, 150, 71, 21));
        lbl_Sunrise->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        lbl_Sunset = new QLabel(centralwidget);
        lbl_Sunset->setObjectName(QStringLiteral("lbl_Sunset"));
        lbl_Sunset->setGeometry(QRect(620, 170, 71, 21));
        lbl_Sunset->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        lbl_showSunrise = new QLabel(centralwidget);
        lbl_showSunrise->setObjectName(QStringLiteral("lbl_showSunrise"));
        lbl_showSunrise->setGeometry(QRect(700, 150, 71, 21));
        lbl_showSunrise->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        lbl_showSunset = new QLabel(centralwidget);
        lbl_showSunset->setObjectName(QStringLiteral("lbl_showSunset"));
        lbl_showSunset->setGeometry(QRect(700, 170, 71, 21));
        lbl_showSunset->setStyleSheet(QLatin1String("color: rgb(40, 40, 40);\n"
"font: 75 12pt \"MS Shell Dlg 2\";\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart Home Control System", Q_NULLPTR));
        btn_lightOn->setText(QApplication::translate("MainWindow", "ON", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Light", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Shutters", Q_NULLPTR));
        btn_shuttersUp->setText(QApplication::translate("MainWindow", "UP", Q_NULLPTR));
        btn_shuttersDown->setText(QApplication::translate("MainWindow", "DOWN", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Tilt Window", Q_NULLPTR));
        btn_tilt->setText(QApplication::translate("MainWindow", "Tilt", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Temperature", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "22\302\260", Q_NULLPTR));
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
        weatherImage->setText(QApplication::translate("MainWindow", "weatherImage", Q_NULLPTR));
        weatherDesc->setText(QApplication::translate("MainWindow", "No data available", Q_NULLPTR));
        PID_value_text->setText(QApplication::translate("MainWindow", "PID value", Q_NULLPTR));
        display_PIDvalue->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "Today's weather", Q_NULLPTR));
        lbl_Sunrise->setText(QApplication::translate("MainWindow", "Sunrise", Q_NULLPTR));
        lbl_Sunset->setText(QApplication::translate("MainWindow", "Sunset", Q_NULLPTR));
        lbl_showSunrise->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        lbl_showSunset->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

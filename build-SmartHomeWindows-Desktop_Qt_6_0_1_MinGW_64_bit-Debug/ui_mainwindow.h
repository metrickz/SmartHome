/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btn_lightOff;
    QPushButton *btn_lightOn;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_4;
    QPushButton *pushButton_5;
    QLabel *label_5;
    QSlider *horizontalSlider_2;
    QLabel *label_6;
    QLabel *label_7;
    QCalendarWidget *calendarWidget;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_Port;
    QPushButton *pushButton_Listen;
    QPushButton *pushButton_Send;
    QTextEdit *textEdit_Recv;
    QTextEdit *textEdit_Send;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1143, 412);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btn_lightOff = new QPushButton(centralwidget);
        btn_lightOff->setObjectName(QString::fromUtf8("btn_lightOff"));
        btn_lightOff->setGeometry(QRect(50, 40, 51, 31));
        btn_lightOn = new QPushButton(centralwidget);
        btn_lightOn->setObjectName(QString::fromUtf8("btn_lightOn"));
        btn_lightOn->setGeometry(QRect(160, 40, 51, 31));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(50, 80, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 10, 31, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 120, 51, 21));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 150, 71, 51));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(130, 150, 71, 51));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 220, 71, 21));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(50, 250, 71, 51));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 330, 71, 21));
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(40, 360, 160, 16));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 370, 21, 21));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(190, 370, 21, 21));
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(380, 10, 281, 171));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(370, 240, 111, 21));
        QFont font;
        font.setPointSize(14);
        label_8->setFont(font);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(370, 310, 111, 21));
        label_9->setFont(font);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(370, 210, 111, 21));
        label_10->setFont(font);
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(370, 270, 111, 31));
        label_11->setFont(font);
        lineEdit_Port = new QLineEdit(centralwidget);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));
        lineEdit_Port->setGeometry(QRect(690, 30, 131, 21));
        pushButton_Listen = new QPushButton(centralwidget);
        pushButton_Listen->setObjectName(QString::fromUtf8("pushButton_Listen"));
        pushButton_Listen->setGeometry(QRect(830, 30, 101, 21));
        pushButton_Send = new QPushButton(centralwidget);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));
        pushButton_Send->setGeometry(QRect(850, 140, 101, 21));
        textEdit_Recv = new QTextEdit(centralwidget);
        textEdit_Recv->setObjectName(QString::fromUtf8("textEdit_Recv"));
        textEdit_Recv->setGeometry(QRect(690, 60, 141, 70));
        textEdit_Send = new QTextEdit(centralwidget);
        textEdit_Send->setObjectName(QString::fromUtf8("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(690, 140, 141, 21));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Obis Smart Home Control System", nullptr));
        btn_lightOff->setText(QCoreApplication::translate("MainWindow", "OFF", nullptr));
        btn_lightOn->setText(QCoreApplication::translate("MainWindow", "ON", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Shutters", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "UP", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "DOWN", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Tilt Window", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "TILT", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "20\302\260", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "28\302\260", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Humidity", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Air pressure", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Temperature", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        pushButton_Listen->setText(QCoreApplication::translate("MainWindow", "Listen", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

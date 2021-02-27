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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_Port;
    QPushButton *pushButton_Listen;
    QPushButton *pushButton_Send;
    QTextEdit *textEdit_Recv;
    QTextEdit *textEdit_Send;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(501, 388);
        MainWindow->setBaseSize(QSize(0, 0));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_Port = new QLineEdit(centralwidget);
        lineEdit_Port->setObjectName(QString::fromUtf8("lineEdit_Port"));
        lineEdit_Port->setGeometry(QRect(60, 10, 113, 20));
        pushButton_Listen = new QPushButton(centralwidget);
        pushButton_Listen->setObjectName(QString::fromUtf8("pushButton_Listen"));
        pushButton_Listen->setGeometry(QRect(180, 10, 171, 23));
        pushButton_Send = new QPushButton(centralwidget);
        pushButton_Send->setObjectName(QString::fromUtf8("pushButton_Send"));
        pushButton_Send->setGeometry(QRect(270, 270, 101, 31));
        textEdit_Recv = new QTextEdit(centralwidget);
        textEdit_Recv->setObjectName(QString::fromUtf8("textEdit_Recv"));
        textEdit_Recv->setGeometry(QRect(60, 80, 321, 171));
        textEdit_Send = new QTextEdit(centralwidget);
        textEdit_Send->setObjectName(QString::fromUtf8("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(60, 270, 191, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 501, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Listen->setText(QCoreApplication::translate("MainWindow", "Listen", nullptr));
        pushButton_Send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *registerbtn;
    QPushButton *registerbtn_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1355, 724);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/1.jpg);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        registerbtn = new QPushButton(centralwidget);
        registerbtn->setObjectName("registerbtn");
        registerbtn->setEnabled(true);
        registerbtn->setGeometry(QRect(250, 590, 391, 81));
        registerbtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 36pt \"Segoe UI\";\n"
"border: none;\n"
"border-radius: 15%;\n"
"color:black;"));
        registerbtn_2 = new QPushButton(centralwidget);
        registerbtn_2->setObjectName("registerbtn_2");
        registerbtn_2->setEnabled(true);
        registerbtn_2->setGeometry(QRect(800, 590, 391, 81));
        registerbtn_2->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 36pt \"Segoe UI\";\n"
"border: none;\n"
"border-radius: 15%;\n"
"color:black;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        registerbtn->setText(QCoreApplication::translate("MainWindow", "Register", nullptr));
        registerbtn_2->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

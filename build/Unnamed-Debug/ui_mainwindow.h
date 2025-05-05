/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
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
    QPushButton *registerBtn;
    QPushButton *signInBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1349, 731);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/1.jpg);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        registerBtn = new QPushButton(centralwidget);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setGeometry(QRect(250, 590, 411, 81));
        registerBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/darkblue.jpg);\n"
"border:none;\n"
"border-radius: 15%;\n"
"color: white;\n"
"font: 700 20pt \"Segoe UI\";"));
        signInBtn = new QPushButton(centralwidget);
        signInBtn->setObjectName("signInBtn");
        signInBtn->setGeometry(QRect(780, 590, 411, 81));
        signInBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/darkblue.jpg);\n"
"border:none;\n"
"border-radius: 15%;\n"
"color: white;\n"
"font: 700 20pt \"Segoe UI\";"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        registerBtn->setText(QCoreApplication::translate("MainWindow", "REGISTER NOW", nullptr));
        signInBtn->setText(QCoreApplication::translate("MainWindow", "SIGN IN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

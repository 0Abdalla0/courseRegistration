/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginWindow
{
public:
    QFrame *frame;
    QPushButton *SignInBtn;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_pass;
    QPushButton *DontHaveBtn;

    void setupUi(QDialog *loginWindow)
    {
        if (loginWindow->objectName().isEmpty())
            loginWindow->setObjectName("loginWindow");
        loginWindow->resize(1354, 657);
        frame = new QFrame(loginWindow);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1361, 651));
        frame->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/3.jpg);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        SignInBtn = new QPushButton(frame);
        SignInBtn->setObjectName("SignInBtn");
        SignInBtn->setGeometry(QRect(600, 490, 251, 51));
        SignInBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/blue.jpg);\n"
"border:none;\n"
"border-radius: 15%;\n"
"color: white;\n"
"font: 700 14pt \"Segoe UI\";"));
        lineEdit_ID = new QLineEdit(frame);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(450, 350, 581, 31));
        lineEdit_ID->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;"));
        lineEdit_pass = new QLineEdit(frame);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(450, 430, 581, 31));
        lineEdit_pass->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;"));
        DontHaveBtn = new QPushButton(frame);
        DontHaveBtn->setObjectName("DontHaveBtn");
        DontHaveBtn->setGeometry(QRect(570, 560, 311, 41));
        DontHaveBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/blue.jpg);\n"
"border:none;\n"
"border-radius: 15%;\n"
"color: white;\n"
"font: 700 14pt \"Segoe UI\";"));

        retranslateUi(loginWindow);

        QMetaObject::connectSlotsByName(loginWindow);
    } // setupUi

    void retranslateUi(QDialog *loginWindow)
    {
        loginWindow->setWindowTitle(QCoreApplication::translate("loginWindow", "Dialog", nullptr));
        SignInBtn->setText(QCoreApplication::translate("loginWindow", "Sign in", nullptr));
        lineEdit_ID->setText(QString());
        DontHaveBtn->setText(QCoreApplication::translate("loginWindow", "Dont't have an account?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginWindow: public Ui_loginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

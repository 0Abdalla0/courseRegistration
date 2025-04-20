/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_signup
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_gpa;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_confirmPass;

    void setupUi(QDialog *signup)
    {
        if (signup->objectName().isEmpty())
            signup->setObjectName("signup");
        signup->resize(1363, 755);
        signup->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/2.jpg);"));
        pushButton = new QPushButton(signup);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 640, 331, 51));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/blue.jpg);\n"
"border:none;\n"
"border-radius: 15%;\n"
"color: white;\n"
"font: 700 12pt \"Segoe UI\";"));
        pushButton_2 = new QPushButton(signup);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(620, 570, 221, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/blue.jpg);\n"
"border:none;\n"
"border-radius: 15%;\n"
"color: white;\n"
"font: 700 12pt \"Segoe UI\";"));
        lineEdit_name = new QLineEdit(signup);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(450, 210, 581, 31));
        lineEdit_name->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;"));
        lineEdit_id = new QLineEdit(signup);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(450, 280, 581, 31));
        lineEdit_id->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;"));
        lineEdit_gpa = new QLineEdit(signup);
        lineEdit_gpa->setObjectName("lineEdit_gpa");
        lineEdit_gpa->setGeometry(QRect(450, 360, 581, 31));
        lineEdit_gpa->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;"));
        lineEdit_pass = new QLineEdit(signup);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(450, 430, 581, 31));
        lineEdit_pass->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;"));
        lineEdit_confirmPass = new QLineEdit(signup);
        lineEdit_confirmPass->setObjectName("lineEdit_confirmPass");
        lineEdit_confirmPass->setGeometry(QRect(450, 500, 581, 31));
        lineEdit_confirmPass->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;"));

        retranslateUi(signup);

        QMetaObject::connectSlotsByName(signup);
    } // setupUi

    void retranslateUi(QDialog *signup)
    {
        signup->setWindowTitle(QCoreApplication::translate("signup", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("signup", "Already have an account?", nullptr));
        pushButton_2->setText(QCoreApplication::translate("signup", "REGISTER", nullptr));
        lineEdit_name->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class signup: public Ui_signup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H

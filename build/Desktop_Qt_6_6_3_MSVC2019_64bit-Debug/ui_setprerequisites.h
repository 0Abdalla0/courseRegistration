/********************************************************************************
** Form generated from reading UI file 'setprerequisites.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPREREQUISITES_H
#define UI_SETPREREQUISITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setPrerequisites
{
public:
    QPushButton *backBTN;
    QLineEdit *prerequisites_input;
    QPushButton *setBtn;
    QComboBox *coursescmb;

    void setupUi(QDialog *setPrerequisites)
    {
        if (setPrerequisites->objectName().isEmpty())
            setPrerequisites->setObjectName("setPrerequisites");
        setPrerequisites->resize(1244, 609);
        setPrerequisites->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/setPre.jpg);"));
        backBTN = new QPushButton(setPrerequisites);
        backBTN->setObjectName("backBTN");
        backBTN->setGeometry(QRect(20, 560, 81, 31));
        backBTN->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));
        prerequisites_input = new QLineEdit(setPrerequisites);
        prerequisites_input->setObjectName("prerequisites_input");
        prerequisites_input->setGeometry(QRect(420, 390, 601, 51));
        prerequisites_input->setStyleSheet(QString::fromUtf8("border-radius: 15%;\n"
"color:black;"));
        setBtn = new QPushButton(setPrerequisites);
        setBtn->setObjectName("setBtn");
        setBtn->setGeometry(QRect(1110, 553, 81, 41));
        setBtn->setStyleSheet(QString::fromUtf8("font: 22pt \"Segoe UI\";\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border-radius:15%;"));
        coursescmb = new QComboBox(setPrerequisites);
        coursescmb->setObjectName("coursescmb");
        coursescmb->setGeometry(QRect(430, 270, 581, 41));
        coursescmb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"border:1px solid black;\n"
"border-radius:15%;\n"
"color:black;"));

        retranslateUi(setPrerequisites);

        QMetaObject::connectSlotsByName(setPrerequisites);
    } // setupUi

    void retranslateUi(QDialog *setPrerequisites)
    {
        setPrerequisites->setWindowTitle(QCoreApplication::translate("setPrerequisites", "Dialog", nullptr));
        backBTN->setText(QCoreApplication::translate("setPrerequisites", "BACK", nullptr));
        setBtn->setText(QCoreApplication::translate("setPrerequisites", "SET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setPrerequisites: public Ui_setPrerequisites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPREREQUISITES_H

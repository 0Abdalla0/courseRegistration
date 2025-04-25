/********************************************************************************
** Form generated from reading UI file 'setprerequisites.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPREREQUISITES_H
#define UI_SETPREREQUISITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setPrerequisites
{
public:
    QPushButton *pushButton_2;
    QLineEdit *courseid_input;
    QLineEdit *prerequisites_input;
    QPushButton *setbtn;
    QPushButton *pushButton;

    void setupUi(QDialog *setPrerequisites)
    {
        if (setPrerequisites->objectName().isEmpty())
            setPrerequisites->setObjectName("setPrerequisites");
        setPrerequisites->resize(1244, 609);
        setPrerequisites->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/setPre.jpg);"));
        pushButton_2 = new QPushButton(setPrerequisites);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 560, 81, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));
        courseid_input = new QLineEdit(setPrerequisites);
        courseid_input->setObjectName("courseid_input");
        courseid_input->setGeometry(QRect(422, 267, 601, 51));
        courseid_input->setStyleSheet(QString::fromUtf8("border-radius: 15%;\n"
"color: black;"));
        prerequisites_input = new QLineEdit(setPrerequisites);
        prerequisites_input->setObjectName("prerequisites_input");
        prerequisites_input->setGeometry(QRect(420, 390, 601, 51));
        prerequisites_input->setStyleSheet(QString::fromUtf8("border-radius: 15%;\n"
"color:black;"));
        setbtn = new QPushButton(setPrerequisites);
        setbtn->setObjectName("setbtn");
        setbtn->setGeometry(QRect(1070, 520, 83, 61));
        pushButton = new QPushButton(setPrerequisites);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(400, 500, 121, 41));

        retranslateUi(setPrerequisites);

        QMetaObject::connectSlotsByName(setPrerequisites);
    } // setupUi

    void retranslateUi(QDialog *setPrerequisites)
    {
        setPrerequisites->setWindowTitle(QCoreApplication::translate("setPrerequisites", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("setPrerequisites", "BACK", nullptr));
        setbtn->setText(QCoreApplication::translate("setPrerequisites", "SET", nullptr));
        pushButton->setText(QCoreApplication::translate("setPrerequisites", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setPrerequisites: public Ui_setPrerequisites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPREREQUISITES_H

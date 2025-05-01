/********************************************************************************
** Form generated from reading UI file 'checkprerequisites.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKPREREQUISITES_H
#define UI_CHECKPREREQUISITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_checkprerequisites
{
public:
    QComboBox *courseID_Cmb;
    QComboBox *prerequisetsID_Cmb;

    void setupUi(QDialog *checkprerequisites)
    {
        if (checkprerequisites->objectName().isEmpty())
            checkprerequisites->setObjectName("checkprerequisites");
        checkprerequisites->resize(1363, 672);
        checkprerequisites->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/checkPrerequitis.jpg);"));
        courseID_Cmb = new QComboBox(checkprerequisites);
        courseID_Cmb->setObjectName("courseID_Cmb");
        courseID_Cmb->setGeometry(QRect(390, 280, 591, 51));
        courseID_Cmb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"border:1px solid black;\n"
"border-radius:15%;\n"
"color:black;"));
        prerequisetsID_Cmb = new QComboBox(checkprerequisites);
        prerequisetsID_Cmb->setObjectName("prerequisetsID_Cmb");
        prerequisetsID_Cmb->setGeometry(QRect(390, 410, 591, 51));
        prerequisetsID_Cmb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"border:1px solid black;\n"
"border-radius:15%;\n"
"color:black;"));

        retranslateUi(checkprerequisites);

        QMetaObject::connectSlotsByName(checkprerequisites);
    } // setupUi

    void retranslateUi(QDialog *checkprerequisites)
    {
        checkprerequisites->setWindowTitle(QCoreApplication::translate("checkprerequisites", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class checkprerequisites: public Ui_checkprerequisites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKPREREQUISITES_H

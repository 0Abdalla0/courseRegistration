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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_setPrerequisites
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;

    void setupUi(QDialog *setPrerequisites)
    {
        if (setPrerequisites->objectName().isEmpty())
            setPrerequisites->setObjectName("setPrerequisites");
        setPrerequisites->resize(1244, 609);
        setPrerequisites->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/setPre.jpg);"));
        pushButton = new QPushButton(setPrerequisites);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1050, 520, 131, 51));
        pushButton->setStyleSheet(QString::fromUtf8("border:none;\n"
"border-radius:15%;\n"
"color:black;\n"
"font: 22pt \"Segoe UI\";"));
        pushButton_2 = new QPushButton(setPrerequisites);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(20, 560, 81, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));
        comboBox = new QComboBox(setPrerequisites);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(440, 270, 561, 41));
        comboBox->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border-radius:15%;"));

        retranslateUi(setPrerequisites);

        QMetaObject::connectSlotsByName(setPrerequisites);
    } // setupUi

    void retranslateUi(QDialog *setPrerequisites)
    {
        setPrerequisites->setWindowTitle(QCoreApplication::translate("setPrerequisites", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("setPrerequisites", "SET", nullptr));
        pushButton_2->setText(QCoreApplication::translate("setPrerequisites", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setPrerequisites: public Ui_setPrerequisites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPREREQUISITES_H

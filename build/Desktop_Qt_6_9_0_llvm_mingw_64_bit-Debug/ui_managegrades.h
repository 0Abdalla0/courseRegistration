/********************************************************************************
** Form generated from reading UI file 'managegrades.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEGRADES_H
#define UI_MANAGEGRADES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_manageGrades
{
public:
    QPushButton *addGradeBtn;
    QComboBox *courseNameCmb;
    QComboBox *studIdCmb;
    QComboBox *gradeCmb;
    QPushButton *backBtn;

    void setupUi(QDialog *manageGrades)
    {
        if (manageGrades->objectName().isEmpty())
            manageGrades->setObjectName("manageGrades");
        manageGrades->resize(1364, 728);
        manageGrades->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/6.jpg);"));
        addGradeBtn = new QPushButton(manageGrades);
        addGradeBtn->setObjectName("addGradeBtn");
        addGradeBtn->setGeometry(QRect(640, 590, 151, 61));
        addGradeBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 350 18pt \"Segoe UI\";\n"
"color:black;\n"
"border:none;\n"
"border-radius:15%;"));
        courseNameCmb = new QComboBox(manageGrades);
        courseNameCmb->setObjectName("courseNameCmb");
        courseNameCmb->setGeometry(QRect(420, 350, 601, 51));
        courseNameCmb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"border:1px solid black;\n"
"border-radius:15%;\n"
"color:black;"));
        studIdCmb = new QComboBox(manageGrades);
        studIdCmb->setObjectName("studIdCmb");
        studIdCmb->setGeometry(QRect(410, 240, 601, 51));
        studIdCmb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"border:1px solid black;\n"
"border-radius:15%;\n"
"color:black;"));
        gradeCmb = new QComboBox(manageGrades);
        gradeCmb->setObjectName("gradeCmb");
        gradeCmb->setGeometry(QRect(410, 460, 141, 61));
        gradeCmb->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"border:1px solid black;\n"
"border-radius:15%;\n"
"color:black;"));
        backBtn = new QPushButton(manageGrades);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(20, 680, 80, 31));
        backBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));

        retranslateUi(manageGrades);

        QMetaObject::connectSlotsByName(manageGrades);
    } // setupUi

    void retranslateUi(QDialog *manageGrades)
    {
        manageGrades->setWindowTitle(QCoreApplication::translate("manageGrades", "Dialog", nullptr));
        addGradeBtn->setText(QCoreApplication::translate("manageGrades", "ADD", nullptr));
        backBtn->setText(QCoreApplication::translate("manageGrades", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manageGrades: public Ui_manageGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEGRADES_H

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
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_manageGrades
{
public:
    QPushButton *addGradeBtn;
    QLineEdit *studIDtxt;

    void setupUi(QDialog *manageGrades)
    {
        if (manageGrades->objectName().isEmpty())
            manageGrades->setObjectName("manageGrades");
        manageGrades->resize(1395, 728);
        manageGrades->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/6.jpg);"));
        addGradeBtn = new QPushButton(manageGrades);
        addGradeBtn->setObjectName("addGradeBtn");
        addGradeBtn->setGeometry(QRect(640, 590, 151, 61));
        addGradeBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 350 18pt \"Segoe UI\";\n"
"color:black;\n"
"border:none;\n"
"border-radius:15%;"));
        studIDtxt = new QLineEdit(manageGrades);
        studIDtxt->setObjectName("studIDtxt");
        studIDtxt->setGeometry(QRect(420, 240, 581, 31));
        studIDtxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);"));

        retranslateUi(manageGrades);

        QMetaObject::connectSlotsByName(manageGrades);
    } // setupUi

    void retranslateUi(QDialog *manageGrades)
    {
        manageGrades->setWindowTitle(QCoreApplication::translate("manageGrades", "Dialog", nullptr));
        addGradeBtn->setText(QCoreApplication::translate("manageGrades", "ADD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manageGrades: public Ui_manageGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEGRADES_H

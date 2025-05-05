/********************************************************************************
** Form generated from reading UI file 'studentpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPAGE_H
#define UI_STUDENTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_studentPage
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *studentPage)
    {
        if (studentPage->objectName().isEmpty())
            studentPage->setObjectName("studentPage");
        studentPage->resize(1396, 720);
        studentPage->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/8.jpg);"));
        pushButton_2 = new QPushButton(studentPage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(330, 390, 241, 221));
        pushButton_2->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/imgs/images/blue.jpg);\n"
"font: 22pt \"Segoe UI\" bold;\n"
"color:white;\n"
"border:none;\n"
"border-radius:15%;"));
        pushButton_3 = new QPushButton(studentPage);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(820, 140, 241, 221));
        pushButton_3->setStyleSheet(QString::fromUtf8("\n"
"background-image: url(:/imgs/images/blue.jpg);\n"
"font: 22pt \"Segoe UI\" bold;\n"
"color:white;\n"
"border:none;\n"
"border-radius:15%;"));

        retranslateUi(studentPage);

        QMetaObject::connectSlotsByName(studentPage);
    } // setupUi

    void retranslateUi(QDialog *studentPage)
    {
        studentPage->setWindowTitle(QCoreApplication::translate("studentPage", "Dialog", nullptr));
        pushButton_2->setText(QCoreApplication::translate("studentPage", "CHECK \n"
"PREREQUISITES", nullptr));
        pushButton_3->setText(QCoreApplication::translate("studentPage", "VIEW \n"
"GRADES", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentPage: public Ui_studentPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPAGE_H

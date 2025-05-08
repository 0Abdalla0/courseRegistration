/********************************************************************************
** Form generated from reading UI file 'registercourse.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERCOURSE_H
#define UI_REGISTERCOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_registerCourse
{
public:
    QPushButton *backBTN;
    QTableWidget *titleItem;
    QPushButton *registerBtn;

    void setupUi(QDialog *registerCourse)
    {
        if (registerCourse->objectName().isEmpty())
            registerCourse->setObjectName("registerCourse");
        registerCourse->resize(1326, 772);
        registerCourse->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/register.jpg);"));
        backBTN = new QPushButton(registerCourse);
        backBTN->setObjectName("backBTN");
        backBTN->setGeometry(QRect(40, 730, 151, 41));
        backBTN->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/blue.jpg);\n"
"color:white;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));
        titleItem = new QTableWidget(registerCourse);
        titleItem->setObjectName("titleItem");
        titleItem->setGeometry(QRect(450, 250, 481, 441));
        titleItem->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 14pt \"Segoe UI\";\n"
"border-radius:25%"));
        registerBtn = new QPushButton(registerCourse);
        registerBtn->setObjectName("registerBtn");
        registerBtn->setGeometry(QRect(1070, 400, 151, 121));
        registerBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:blue;\n"
"font: 22pt \"Segoe UI\";\n"
"border-radius:25%;\n"
"\n"
""));

        retranslateUi(registerCourse);

        QMetaObject::connectSlotsByName(registerCourse);
    } // setupUi

    void retranslateUi(QDialog *registerCourse)
    {
        registerCourse->setWindowTitle(QCoreApplication::translate("registerCourse", "Dialog", nullptr));
        backBTN->setText(QCoreApplication::translate("registerCourse", "BACK", nullptr));
        registerBtn->setText(QCoreApplication::translate("registerCourse", "REGISTER", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerCourse: public Ui_registerCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERCOURSE_H

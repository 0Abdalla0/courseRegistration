/********************************************************************************
** Form generated from reading UI file 'adminpage.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINPAGE_H
#define UI_ADMINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_adminPage
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *manageGrades;
    QLabel *coursesCnt;
    QLabel *studCnt;

    void setupUi(QDialog *adminPage)
    {
        if (adminPage->objectName().isEmpty())
            adminPage->setObjectName("adminPage");
        adminPage->resize(1398, 738);
        adminPage->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/4.jpg);"));
        pushButton = new QPushButton(adminPage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1280, 690, 91, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));
        pushButton_2 = new QPushButton(adminPage);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 190, 381, 181));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 22pt \"Segoe UI\";\n"
"color:black;\n"
"border:none;\n"
"border-radius:15%;"));
        pushButton_3 = new QPushButton(adminPage);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(830, 190, 381, 181));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 22pt \"Segoe UI\";\n"
"color:black;\n"
"border:none;\n"
"border-radius:15%;"));
        manageGrades = new QPushButton(adminPage);
        manageGrades->setObjectName("manageGrades");
        manageGrades->setGeometry(QRect(480, 480, 461, 191));
        manageGrades->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 22pt \"Segoe UI\";\n"
"color:black;\n"
"border:none;\n"
"border-radius:15%;"));
        coursesCnt = new QLabel(adminPage);
        coursesCnt->setObjectName("coursesCnt");
        coursesCnt->setGeometry(QRect(380, 30, 41, 41));
        coursesCnt->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 700 26pt \"Segoe UI\";\n"
"background-image: url(:/imgs/images/white.jpg);"));
        studCnt = new QLabel(adminPage);
        studCnt->setObjectName("studCnt");
        studCnt->setGeometry(QRect(780, 30, 41, 41));
        studCnt->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 700 26pt \"Segoe UI\";\n"
"background-image: url(:/imgs/images/white.jpg);"));

        retranslateUi(adminPage);

        QMetaObject::connectSlotsByName(adminPage);
    } // setupUi

    void retranslateUi(QDialog *adminPage)
    {
        adminPage->setWindowTitle(QCoreApplication::translate("adminPage", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("adminPage", "HOME", nullptr));
        pushButton_2->setText(QCoreApplication::translate("adminPage", "UPLOAD COURSE", nullptr));
        pushButton_3->setText(QCoreApplication::translate("adminPage", "SET PREREQUISITES", nullptr));
        manageGrades->setText(QCoreApplication::translate("adminPage", "MANAGE STUDENTS' GRADES", nullptr));
        coursesCnt->setText(QCoreApplication::translate("adminPage", "0", nullptr));
        studCnt->setText(QCoreApplication::translate("adminPage", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminPage: public Ui_adminPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINPAGE_H

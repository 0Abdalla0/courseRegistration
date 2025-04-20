/********************************************************************************
** Form generated from reading UI file 'signupwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOW_H
#define UI_SIGNUPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SignUpWindow
{
public:
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton;

    void setupUi(QDialog *SignUpWindow)
    {
        if (SignUpWindow->objectName().isEmpty())
            SignUpWindow->setObjectName("SignUpWindow");
        SignUpWindow->resize(1272, 703);
        SignUpWindow->setStyleSheet(QString::fromUtf8("image: url(:/res/2.jpg);"));
        lineEdit = new QLineEdit(SignUpWindow);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(420, 200, 541, 31));
        lineEdit_2 = new QLineEdit(SignUpWindow);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(420, 270, 541, 31));
        lineEdit_3 = new QLineEdit(SignUpWindow);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(420, 340, 541, 31));
        lineEdit_4 = new QLineEdit(SignUpWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(420, 400, 541, 31));
        lineEdit_5 = new QLineEdit(SignUpWindow);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(420, 470, 541, 31));
        pushButton = new QPushButton(SignUpWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 550, 391, 101));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: transparent;"));

        retranslateUi(SignUpWindow);

        QMetaObject::connectSlotsByName(SignUpWindow);
    } // setupUi

    void retranslateUi(QDialog *SignUpWindow)
    {
        SignUpWindow->setWindowTitle(QCoreApplication::translate("SignUpWindow", "Dialog", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SignUpWindow: public Ui_SignUpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOW_H

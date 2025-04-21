/********************************************************************************
** Form generated from reading UI file 'uploadcourse.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADCOURSE_H
#define UI_UPLOADCOURSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_uploadCourse
{
public:
    QLineEdit *codetxt;
    QLineEdit *nametxt;
    QLineEdit *disctxt;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *uploadCourse)
    {
        if (uploadCourse->objectName().isEmpty())
            uploadCourse->setObjectName("uploadCourse");
        uploadCourse->resize(1351, 718);
        uploadCourse->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/5.jpg);"));
        codetxt = new QLineEdit(uploadCourse);
        codetxt->setObjectName("codetxt");
        codetxt->setGeometry(QRect(420, 240, 581, 31));
        codetxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        nametxt = new QLineEdit(uploadCourse);
        nametxt->setObjectName("nametxt");
        nametxt->setGeometry(QRect(420, 340, 581, 31));
        nametxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        disctxt = new QLineEdit(uploadCourse);
        disctxt->setObjectName("disctxt");
        disctxt->setGeometry(QRect(430, 480, 561, 71));
        disctxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        pushButton = new QPushButton(uploadCourse);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(590, 620, 211, 24));
        pushButton->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"color:black;\n"
"border:none;\n"
"border-radius:15%;\n"
""));
        pushButton_2 = new QPushButton(uploadCourse);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(30, 670, 80, 24));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));

        retranslateUi(uploadCourse);

        QMetaObject::connectSlotsByName(uploadCourse);
    } // setupUi

    void retranslateUi(QDialog *uploadCourse)
    {
        uploadCourse->setWindowTitle(QCoreApplication::translate("uploadCourse", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("uploadCourse", "UPLOAD COURSE", nullptr));
        pushButton_2->setText(QCoreApplication::translate("uploadCourse", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uploadCourse: public Ui_uploadCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADCOURSE_H

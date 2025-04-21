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
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_uploadCourse
{
public:
    QLineEdit *codetxt;
    QLineEdit *nametxt;
    QLineEdit *syllabustxt;
    QPushButton *uploadBtn;
    QPushButton *backBtn;
    QLineEdit *instNametxt;
    QLineEdit *instemailtxt;
    QSpinBox *creditHours;

    void setupUi(QDialog *uploadCourse)
    {
        if (uploadCourse->objectName().isEmpty())
            uploadCourse->setObjectName("uploadCourse");
        uploadCourse->resize(1351, 718);
        uploadCourse->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/uploadCourse.jpg);"));
        codetxt = new QLineEdit(uploadCourse);
        codetxt->setObjectName("codetxt");
        codetxt->setGeometry(QRect(270, 190, 721, 31));
        codetxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        nametxt = new QLineEdit(uploadCourse);
        nametxt->setObjectName("nametxt");
        nametxt->setGeometry(QRect(260, 290, 731, 31));
        nametxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        syllabustxt = new QLineEdit(uploadCourse);
        syllabustxt->setObjectName("syllabustxt");
        syllabustxt->setGeometry(QRect(260, 390, 731, 31));
        syllabustxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        uploadBtn = new QPushButton(uploadCourse);
        uploadBtn->setObjectName("uploadBtn");
        uploadBtn->setGeometry(QRect(1110, 350, 211, 61));
        uploadBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"color:black;\n"
"border:none;\n"
"border-radius:15%;\n"
""));
        backBtn = new QPushButton(uploadCourse);
        backBtn->setObjectName("backBtn");
        backBtn->setGeometry(QRect(30, 670, 80, 31));
        backBtn->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"color:black;\n"
"border:none;\n"
"font: 18pt \"Segoe UI\";\n"
"border-radius:15%;\n"
""));
        instNametxt = new QLineEdit(uploadCourse);
        instNametxt->setObjectName("instNametxt");
        instNametxt->setGeometry(QRect(260, 460, 731, 31));
        instNametxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        instemailtxt = new QLineEdit(uploadCourse);
        instemailtxt->setObjectName("instemailtxt");
        instemailtxt->setGeometry(QRect(260, 540, 731, 31));
        instemailtxt->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"border:none;\n"
"font-size: 16pt;\n"
"color: black;\n"
""));
        creditHours = new QSpinBox(uploadCourse);
        creditHours->setObjectName("creditHours");
        creditHours->setGeometry(QRect(270, 600, 81, 31));
        creditHours->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);\n"
"font: 18pt \"Segoe UI\";\n"
"border:none;\n"
"border-radius:15%;\n"
"color:black;"));

        retranslateUi(uploadCourse);

        QMetaObject::connectSlotsByName(uploadCourse);
    } // setupUi

    void retranslateUi(QDialog *uploadCourse)
    {
        uploadCourse->setWindowTitle(QCoreApplication::translate("uploadCourse", "Dialog", nullptr));
        uploadBtn->setText(QCoreApplication::translate("uploadCourse", "UPLOAD COURSE", nullptr));
        backBtn->setText(QCoreApplication::translate("uploadCourse", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class uploadCourse: public Ui_uploadCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADCOURSE_H

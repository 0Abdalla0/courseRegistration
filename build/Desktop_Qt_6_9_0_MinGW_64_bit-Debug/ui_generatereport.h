/********************************************************************************
** Form generated from reading UI file 'generatereport.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEREPORT_H
#define UI_GENERATEREPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_generateReport
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widgetCourseName;
    QScrollArea *scrollArea_Id;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widgetGrades;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_3;
    QWidget *widgetSemster;
    QPushButton *pushButton;

    void setupUi(QDialog *generateReport)
    {
        if (generateReport->objectName().isEmpty())
            generateReport->setObjectName("generateReport");
        generateReport->resize(1325, 702);
        generateReport->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/10.jpg);"));
        label = new QLabel(generateReport);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 120, 171, 41));
        QFont font;
        font.setPointSize(28);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-image: url(:/imgs/images/blue.jpg);"));
        label_2 = new QLabel(generateReport);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(620, 120, 171, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-image: url(:/imgs/images/white.jpg);\n"
""));
        label_3 = new QLabel(generateReport);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1030, 120, 171, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-image: url(:/imgs/images/blue.jpg);"));
        scrollArea = new QScrollArea(generateReport);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 294, 471, 391));
        scrollArea->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 469, 389));
        widgetCourseName = new QWidget(scrollAreaWidgetContents);
        widgetCourseName->setObjectName("widgetCourseName");
        widgetCourseName->setGeometry(QRect(0, 0, 471, 391));
        widgetCourseName->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font-size:20px;\n"
""));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_Id = new QScrollArea(generateReport);
        scrollArea_Id->setObjectName("scrollArea_Id");
        scrollArea_Id->setGeometry(QRect(499, 294, 371, 391));
        scrollArea_Id->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);"));
        scrollArea_Id->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 369, 389));
        widgetGrades = new QWidget(scrollAreaWidgetContents_2);
        widgetGrades->setObjectName("widgetGrades");
        widgetGrades->setGeometry(QRect(-1, -1, 371, 391));
        widgetGrades->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font-size:20px;\n"
""));
        scrollArea_Id->setWidget(scrollAreaWidgetContents_2);
        scrollArea_2 = new QScrollArea(generateReport);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(889, 294, 421, 391));
        scrollArea_2->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/white.jpg);"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 419, 389));
        widgetSemster = new QWidget(scrollAreaWidgetContents_3);
        widgetSemster->setObjectName("widgetSemster");
        widgetSemster->setGeometry(QRect(0, -1, 421, 391));
        widgetSemster->setStyleSheet(QString::fromUtf8("color:black;\n"
"background-image: url(:/imgs/images/white.jpg);\n"
"font-size:20px;\n"
""));
        scrollArea_2->setWidget(scrollAreaWidgetContents_3);
        pushButton = new QPushButton(generateReport);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 20, 151, 61));
        pushButton->setStyleSheet(QString::fromUtf8("BORDER-RADIUS:25%;\n"
"background-image: url(:/imgs/images/blue.jpg);\n"
"font: 20pt \"Segoe UI\";\n"
"color:white;"));

        retranslateUi(generateReport);

        QMetaObject::connectSlotsByName(generateReport);
    } // setupUi

    void retranslateUi(QDialog *generateReport)
    {
        generateReport->setWindowTitle(QCoreApplication::translate("generateReport", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("generateReport", "unkown", nullptr));
        label_2->setText(QCoreApplication::translate("generateReport", "0.0", nullptr));
        label_3->setText(QCoreApplication::translate("generateReport", "-1", nullptr));
        pushButton->setText(QCoreApplication::translate("generateReport", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class generateReport: public Ui_generateReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEREPORT_H

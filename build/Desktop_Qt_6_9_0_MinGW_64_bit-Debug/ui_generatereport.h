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
    QWidget *widget;

    void setupUi(QDialog *generateReport)
    {
        if (generateReport->objectName().isEmpty())
            generateReport->setObjectName("generateReport");
        generateReport->resize(1345, 782);
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
        scrollArea->setGeometry(QRect(890, 294, 391, 111));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 389, 109));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 10, 371, 80));
        widget->setStyleSheet(QString::fromUtf8("color:black"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(generateReport);

        QMetaObject::connectSlotsByName(generateReport);
    } // setupUi

    void retranslateUi(QDialog *generateReport)
    {
        generateReport->setWindowTitle(QCoreApplication::translate("generateReport", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("generateReport", "unkown", nullptr));
        label_2->setText(QCoreApplication::translate("generateReport", "0.0", nullptr));
        label_3->setText(QCoreApplication::translate("generateReport", "-1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class generateReport: public Ui_generateReport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEREPORT_H

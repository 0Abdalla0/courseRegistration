/********************************************************************************
** Form generated from reading UI file 'viewgrades.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWGRADES_H
#define UI_VIEWGRADES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_viewGrades
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QDialog *viewGrades)
    {
        if (viewGrades->objectName().isEmpty())
            viewGrades->setObjectName("viewGrades");
        viewGrades->resize(1315, 788);
        viewGrades->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/11.jpg);"));
        label = new QLabel(viewGrades);
        label->setObjectName("label");
        label->setGeometry(QRect(590, 470, 191, 41));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"Segoe UI\";\n"
"color:white;"));
        comboBox = new QComboBox(viewGrades);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(460, 300, 451, 61));
        comboBox->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 127);\n"
"background-image: url(:/imgs/images/blue.jpg);\n"
"border-radius: 15%;\n"
"color:white;\n"
"font: 22pt \"Segoe UI\";"));
        pushButton = new QPushButton(viewGrades);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 620, 151, 51));
        pushButton->setStyleSheet(QString::fromUtf8("BORDER-RADIUS:25%;\n"
"font: 20pt \"Segoe UI\";\n"
"color:white;"));

        retranslateUi(viewGrades);

        QMetaObject::connectSlotsByName(viewGrades);
    } // setupUi

    void retranslateUi(QDialog *viewGrades)
    {
        viewGrades->setWindowTitle(QCoreApplication::translate("viewGrades", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("viewGrades", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("viewGrades", "BACK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewGrades: public Ui_viewGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWGRADES_H

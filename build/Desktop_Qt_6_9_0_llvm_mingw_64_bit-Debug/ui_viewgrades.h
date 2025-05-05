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

QT_BEGIN_NAMESPACE

class Ui_viewGrades
{
public:
    QComboBox *comboBox;
    QLabel *label;

    void setupUi(QDialog *viewGrades)
    {
        if (viewGrades->objectName().isEmpty())
            viewGrades->setObjectName("viewGrades");
        viewGrades->resize(1302, 566);
        viewGrades->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/blue.jpg);"));
        comboBox = new QComboBox(viewGrades);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(400, 200, 491, 41));
        label = new QLabel(viewGrades);
        label->setObjectName("label");
        label->setGeometry(QRect(590, 310, 91, 41));

        retranslateUi(viewGrades);

        QMetaObject::connectSlotsByName(viewGrades);
    } // setupUi

    void retranslateUi(QDialog *viewGrades)
    {
        viewGrades->setWindowTitle(QCoreApplication::translate("viewGrades", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("viewGrades", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class viewGrades: public Ui_viewGrades {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWGRADES_H

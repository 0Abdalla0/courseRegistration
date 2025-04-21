/********************************************************************************
** Form generated from reading UI file 'setprerequisites.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPREREQUISITES_H
#define UI_SETPREREQUISITES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_setPrerequisites
{
public:

    void setupUi(QDialog *setPrerequisites)
    {
        if (setPrerequisites->objectName().isEmpty())
            setPrerequisites->setObjectName("setPrerequisites");
        setPrerequisites->resize(1244, 609);
        setPrerequisites->setStyleSheet(QString::fromUtf8("background-image: url(:/imgs/images/6.jpg);\n"
"background-image: url(:/imgs/images/blue.jpg);"));

        retranslateUi(setPrerequisites);

        QMetaObject::connectSlotsByName(setPrerequisites);
    } // setupUi

    void retranslateUi(QDialog *setPrerequisites)
    {
        setPrerequisites->setWindowTitle(QCoreApplication::translate("setPrerequisites", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setPrerequisites: public Ui_setPrerequisites {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPREREQUISITES_H

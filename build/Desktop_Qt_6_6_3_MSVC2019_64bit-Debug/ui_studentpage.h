/********************************************************************************
** Form generated from reading UI file 'studentpage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTPAGE_H
#define UI_STUDENTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_studentPage
{
public:

    void setupUi(QDialog *studentPage)
    {
        if (studentPage->objectName().isEmpty())
            studentPage->setObjectName("studentPage");
        studentPage->resize(400, 300);

        retranslateUi(studentPage);

        QMetaObject::connectSlotsByName(studentPage);
    } // setupUi

    void retranslateUi(QDialog *studentPage)
    {
        studentPage->setWindowTitle(QCoreApplication::translate("studentPage", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studentPage: public Ui_studentPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTPAGE_H

#include "checkprerequisites.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "adminPage.h"
#include "course.h"
#include "setprerequisites.h"
#include "studentpage.h"
#include "ui_checkprerequisites.h"
#include "ui_setprerequisites.h"
#include "uploadcourse.h"
#include <stack>
#include <vector>

checkprerequisites::checkprerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::checkprerequisites)
{
    ui->setupUi(this);

    prerequisitesTable = setPrerequisites::getPrerequisitesTable();

    for (getPreit = prerequisitesTable.begin(); getPreit != prerequisitesTable.end(); ++getPreit) {
        ui->courseID_Cmb->addItem(QString::number(getPreit->first));
    }

    connect(ui->courseID_Cmb,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &checkprerequisites::on_courseID_Cmb_currentIndexChanged);
    ui->courseID_Cmb->setCurrentIndex(0);
    on_courseID_Cmb_currentIndexChanged(0);
}

checkprerequisites::~checkprerequisites()
{
    delete ui;
}

void checkprerequisites::on_backBTN_clicked()
{
    this->hide();
    studentPage *stdPage = new studentPage();
    stdPage->show();
}

void checkprerequisites::on_courseID_Cmb_currentIndexChanged(int index)
{
    ui->prerequisetsID_Cmb->clear();
    QString courseid = ui->courseID_Cmb->currentText();
    int id = courseid.toInt();
    qDebug() << "Index changed to" << index;

    // Find prerequisites for selected course
    for (getPreit = prerequisitesTable.begin(); getPreit != prerequisitesTable.end(); ++getPreit) {
        if (id == getPreit->first) {
            vector<int> prereqList = getPreit->second;
            vector<int>::iterator vecIt;
            for (vecIt = prereqList.begin(); vecIt != prereqList.end(); ++vecIt) {
                ui->prerequisetsID_Cmb->addItem(QString::number(*vecIt));
            }
            break;
        }
    }
}

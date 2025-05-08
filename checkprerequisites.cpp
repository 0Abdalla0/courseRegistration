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
#include"managegrades.h"

checkprerequisites::checkprerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::checkprerequisites)
{
    ui->setupUi(this);

    prerequisitesTable = setPrerequisites::getPrerequisitesTable();
    getCourseInfo = uploadCourse::getCourseTable();
    for (getPreit = prerequisitesTable.begin(); getPreit != prerequisitesTable.end(); ++getPreit) {
          ui->courseID_Cmb->addItem(getCourseInfo[getPreit->first].getTitle());
    }

    connect(ui->courseID_Cmb,
            QOverload<int>::of(&QComboBox::currentIndexChanged),
            this,
            &checkprerequisites::on_courseID_Cmb_currentIndexChanged);
    ui->courseID_Cmb->setCurrentIndex(0);
    on_courseID_Cmb_currentIndexChanged(0);
    gradesTabel = manageGrades::getGrades();
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
    QString courseName = ui->courseID_Cmb->currentText();
    qDebug() << "Index changed to" << index;

    for (getPreit = prerequisitesTable.begin(); getPreit != prerequisitesTable.end(); ++getPreit) {
        if (courseName == getCourseInfo[getPreit->first].getTitle()) {
            vector<int> prereqList = getPreit->second;
            vector<int>::iterator vecIt;
            for (vecIt = prereqList.begin(); vecIt != prereqList.end(); ++vecIt) {
                 ui->prerequisetsID_Cmb->addItem(getCourseInfo[*vecIt].getTitle());
            }
            break;
        }
    }
}
bool checkprerequisites::checkCourseValidation(int id)
{
    map<int, unordered_map<QString, QString>>::iterator gradesIt;
    for(gradesIt=gradesTabel.begin();gradesIt!=gradesTabel.begin();gradesIt++)
    {
        if(id==gradesIt->first)
        {
            return true;
        }
     }
    return false;
}

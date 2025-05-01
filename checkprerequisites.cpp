#include "checkprerequisites.h"
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

    // unordered_map<int, Course> courseTable = uploadCourse::getCourseTable();
    // unordered_map<int, Course>::iterator uploadCourseit;
    map<int, vector<int>> prerequisitesTable = setPrerequisites::getPrerequisitesTable();
    map<int, vector<int>>::iterator getPreit;

    // Populate courseID combo box
    for (getPreit = prerequisitesTable.begin(); getPreit != prerequisitesTable.end(); ++getPreit) {
        ui->courseID_Cmb->addItem(QString::number(getPreit->first));
    }
    ui->courseID_Cmb->setCurrentIndex(0);
    QString courseid = ui->courseID_Cmb->itemText(0);
    int id = courseid.toInt();

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

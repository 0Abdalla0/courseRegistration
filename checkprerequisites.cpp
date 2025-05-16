#include "checkprerequisites.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "adminPage.h"
#include "course.h"
#include "grade.h"
#include "managegrades.h"
#include "setprerequisites.h"
#include "studentpage.h"
#include "ui_checkprerequisites.h"
#include "ui_setprerequisites.h"
#include "uploadcourse.h"
#include <stack>
#include <vector>
///////////to be commited
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

bool checkprerequisites::checkCourseValidation(int courseId, int studentId)
{
    auto getPreit = prerequisitesTable.find(courseId);
    if (getPreit == prerequisitesTable.end()) {
        return true; // No prerequisites
    }

    const vector<int> &prereqList = getPreit->second;

    for (int prereqId : prereqList) {
        // Check if course info exists
        auto courseIt = getCourseInfo.find(prereqId);
        if (courseIt == getCourseInfo.end()) {
            return false; // Invalid prerequisite course
        }

        QString courseTitle = courseIt->second.getTitle();

        // Look up the student's grade record
        auto studentIt = gradesTabel.find(studentId);
        if (studentIt == gradesTabel.end()) {
            return false; // No grades found for student
        }

        const auto &courses = studentIt->second;
        auto courseGradeIt = courses.find(courseTitle);
        if (courseGradeIt == courses.end() || !courseGradeIt->second) {
            return false; // No grade found for the prerequisite course
        }

        grade *g = courseGradeIt->second;
        if (g->courseGrade == "F") {
            return false; // Student failed the prerequisite
        }
    }

    return true; // All prerequisites passed
}

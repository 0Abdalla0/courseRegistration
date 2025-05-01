#include "checkprerequisites.h"
#include "ui_checkprerequisites.h"
#include "setprerequisites.h"
#include "ui_setprerequisites.h"
#include"adminPage.h"
#include "uploadcourse.h"
#include "course.h"
#include <stack>
#include <QMessageBox>
#include <QTextStream>
#include <vector>
#include<QFile>

checkprerequisites::checkprerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::checkprerequisites)
{
    ui->setupUi(this);
    for (const auto& [id, course] : uploadCourse::getCourseTable()) {
        ui->courseID_Cmb->addItem(QString::number(id));
    }

}

checkprerequisites::~checkprerequisites()
{
    delete ui;
}

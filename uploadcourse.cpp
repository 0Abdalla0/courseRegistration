#include "uploadcourse.h"
#include "ui_uploadcourse.h"
#include<map>
#include<vector>
#include<QMessageBox>
#include "adminpage.h"
#include<iostream>
#include"course.h"
#include<unordered_map>
using namespace std;
//101->programming
//201 -> math
//301 ->elective
uploadCourse::uploadCourse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::uploadCourse)
{
    ui->setupUi(this);
}

uploadCourse::~uploadCourse()
{
    delete ui;
}
unordered_map<int,Course> courseTable;


void uploadCourse::on_uploadBtn_clicked()
{

    QString courseIDString=ui->codetxt->text();
    int courseID= courseIDString.toInt();
    QString courseName=ui->nametxt->text();
    QString courseSyllabus=ui->syllabustxt->text();
    QString instructorName=ui->instNametxt->text();
    QString instructorEmail=ui->instemailtxt->text();
    QString creditHours=ui->creditHours->text();
    int hours = creditHours.toInt();
    static QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+.[A-Za-z]{2,}$)");

    if(courseIDString.isEmpty()|| courseName.isEmpty()||courseSyllabus.isEmpty()||courseSyllabus.isEmpty()||instructorName.isEmpty()||instructorEmail.isEmpty()){
        QMessageBox::warning(this,"FAILURE","Missing INFO.");
    }else if(hours<1 ||hours>4 ){
        QMessageBox::warning(this,"FAILURE","Credit Hour Value is  Out OF Bounds");
    }else if (!emailRegex.match(instructorEmail).hasMatch()) {
        QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
        return;
    }
    else{
        QMessageBox::information(this,"SUCCESSFUL","SUCCESSFULLY UPLOADED COURSE");
        Course course(courseID,courseName,instructorName,instructorEmail,courseSyllabus,hours);
        courseTable[course.getId()]=course;
        unordered_map<int,Course>::iterator it = courseTable.begin();
        while (it != courseTable.end()) {
            cout << (it->second.getId())<<endl;
            cout << (it->second.getInstructorName().toStdString())<<endl;
            cout << (it->second.getInstructorEmail().toStdString())<<endl;
            cout << (it->second.getSyllabus().toStdString())<<endl;
            cout << (it->second.getCreditHours())<<endl;
            it++;
        }
        ui->codetxt->clear();
       ui->nametxt->clear();
       ui->syllabustxt->clear();
       ui->instNametxt->clear();
       ui->instemailtxt->clear();
       ui->creditHours->clear();
    }
}


void uploadCourse::on_backBtn_clicked()
{
    this->hide();
    adminPage* admin=new adminPage();
    admin->show();
}


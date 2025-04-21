#include "uploadcourse.h"
#include "ui_uploadcourse.h"
#include<map>
#include<vector>
#include<QMessageBox>
#include "adminpage.h"
#include<iostream>
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
map<int,vector<QString>> course;


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
    if(courseIDString.isEmpty()|| courseName.isEmpty()||courseSyllabus.isEmpty()||courseSyllabus.isEmpty()||instructorName.isEmpty()||instructorEmail.isEmpty()){
        QMessageBox::warning(this,"FAILURE","Missing INFO.");
    }else{
        if(hours<1 ||hours>4 ){QMessageBox::warning(this,"FAILURE","Credit Hour Value is  Out OF Bounds");}
        static QRegularExpression emailRegex(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+.[A-Za-z]{2,}$)");
        if (!emailRegex.match(instructorEmail).hasMatch()) {
            QMessageBox::warning(this, "Invalid Email", "Please enter a valid email address.");
            return;
        }
        QMessageBox::information(this,"SUCCESSFUL","SUCCESSFULLY UPLOADED COURSE");
        vector<QString> data;
        data.push_back(courseName);
        data.push_back(courseSyllabus);
        data.push_back(instructorName);
        data.push_back(instructorEmail);
        data.push_back(creditHours);
        course[courseID]=data;
        for (int var = 0; var < course[courseID].size(); ++var) {
            cout<<course[courseID][var].toStdString()<<endl;
        }
    }
}


void uploadCourse::on_backBtn_clicked()
{
    this->hide();
    adminPage* admin=new adminPage();
    admin->show();
}


#include "uploadcourse.h"
#include "ui_uploadcourse.h"
#include<map>
#include<vector>
#include<QMessageBox>
#include "adminpage.h"
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
void uploadCourse::on_pushButton_clicked()
{
    QString courseIDString=ui->codetxt->text();
    int courseID= ui->codetxt->text().toInt();
    QString courseName=ui->nametxt->text();
    QString courseDiscription=ui->disctxt->text();
    if(courseIDString.isEmpty()|| courseName.isEmpty()||courseDiscription.isEmpty()){
        QMessageBox::information(this,"FAILURE","Missing INFO.");
    }else{
        QMessageBox::information(this,"SUCCESSFUL","SUCCESSFULLY UPLOADED COURSE");
        vector<QString> data;
        data.push_back(courseName);
        data.push_back(courseDiscription);
        course[courseID]=data;
    }
}


void uploadCourse::on_pushButton_2_clicked()
{
    this->hide();
    adminPage* admin=new adminPage();
    admin->show();
}


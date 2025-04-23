#include "adminpage.h"
#include "ui_adminpage.h"
#include"mainwindow.h"
#include"uploadcourse.h"
#include"course.h"
adminPage::adminPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminPage)
{
    ui->setupUi(this);
}

adminPage::~adminPage()
{
    delete ui;
}

void adminPage::on_pushButton_clicked()
{
    this->hide();
    MainWindow* main = new MainWindow();
    main->show();
}


void adminPage::on_pushButton_2_clicked()
{
    this->hide();
    uploadCourse* uc=new uploadCourse();
    uc->show();
}
void adminPage::updateCnt(int& c){
    QString coursesCnt =QString::number(c);
    ui->coursesCnt->setText(coursesCnt);
}








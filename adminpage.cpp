#include "adminpage.h"
#include "course.h"
#include "mainwindow.h"
#include "setprerequisites.h"
#include "ui_adminpage.h"
#include "uploadcourse.h"
#include"managegrades.h"
adminPage::adminPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminPage)
{
    uploadCourse uc;
    ui->setupUi(this);
    updateCnt(uploadCourse::coursesCnt);
}

adminPage::~adminPage()
{
    delete ui;
}

void adminPage::on_pushButton_clicked()
{
    this->hide();
    MainWindow *main = new MainWindow();
    main->show();
}

void adminPage::on_pushButton_2_clicked()
{
    this->hide();
    uploadCourse *uc = new uploadCourse();
    uc->loadCoursesFromFile("courses.txt");
    uc->show();
}
void adminPage::updateCnt(int &c)
{
    QString coursesCnt = QString::number(c);
    ui->coursesCnt->setText(coursesCnt);
}

void adminPage::on_pushButton_3_clicked()
{
    this->hide();
    setPrerequisites *setPre = new setPrerequisites();
    //uc->loadCoursesFromFile("courses.txt");
    setPre->show();
}

void adminPage::on_manageGrades_clicked()
{
    this->hide();
    manageGrades* mg =new manageGrades();
    mg->show();
}


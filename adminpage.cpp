#include "adminpage.h"
#include "course.h"
#include "mainwindow.h"
#include "ui_adminpage.h"
#include "uploadcourse.h"
#include"setprerequisites.h"
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


#include "studentpage.h"
#include "checkprerequisites.h"
#include "ui_studentpage.h"
#include "viewgrades.h"
#include"generatereport.h"
#include "registercourse.h"
#include "mainwindow.h"
studentPage::studentPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::studentPage)
{
    ui->setupUi(this);
}

studentPage::~studentPage()
{
    delete ui;
}

void studentPage::on_pushButton_2_clicked()
{
    this->hide();
    checkprerequisites *checkPage = new checkprerequisites(this);
    checkPage->show();
}

void studentPage::on_pushButton_3_clicked()
{
    this->hide();
    viewGrades *viewPage = new viewGrades(this);
    viewPage->show();
}

void studentPage::on_pushButton_4_clicked()
{
    this->hide();
    generateReport *genReport = new generateReport(this);
    genReport->show();
}


void studentPage::on_pushButton_5_clicked()
{
    this->hide();
    registerCourse *courseReg = new registerCourse(this);
    courseReg->show();
}


void studentPage::on_pushButton_clicked()
{
    this->hide();
    MainWindow *main = new MainWindow();
    main->show();
}



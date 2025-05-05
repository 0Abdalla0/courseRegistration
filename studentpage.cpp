#include "studentpage.h"
#include "checkprerequisites.h"
#include "ui_studentpage.h"
#include "viewgrades.h"
#include"generatereport.h"
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


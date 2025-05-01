#include "studentpage.h"
#include "ui_studentpage.h"
#include"checkprerequisites.h"

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
    checkprerequisites *checkPage= new checkprerequisites(this);
    checkPage->show();
}


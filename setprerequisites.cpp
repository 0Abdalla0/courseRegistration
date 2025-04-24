#include "setprerequisites.h"
#include "ui_setprerequisites.h"
#include"adminPage.h"
setPrerequisites::setPrerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setPrerequisites)
{
    ui->setupUi(this);
}

setPrerequisites::~setPrerequisites()
{
    delete ui;
}

void setPrerequisites::on_pushButton_2_clicked()
{
    this->hide();
    adminPage *admin = new adminPage();
    admin->show();
}


void setPrerequisites::on_comboBox_activated(int index)
{

}


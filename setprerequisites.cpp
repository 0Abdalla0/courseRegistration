#include "setprerequisites.h"
#include "ui_setprerequisites.h"

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

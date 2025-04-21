#include "studentpage.h"
#include "ui_studentpage.h"

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

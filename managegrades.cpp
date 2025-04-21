#include "managegrades.h"
#include "ui_managegrades.h"

manageGrades::manageGrades(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::manageGrades)
{
    ui->setupUi(this);
}

manageGrades::~manageGrades()
{
    delete ui;
}

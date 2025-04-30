#include "setprerequisites.h"
#include "ui_setprerequisites.h"
#include"adminPage.h"
#include "uploadcourse.h"
#include "course.h"
#include <stack>
#include <QMessageBox>
#include <QTextStream>
#include <vector>

setPrerequisites::setPrerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setPrerequisites)

{

    ui->setupUi(this);
    for (const auto& [id, course] : uploadCourse::getCourseTable()) {
        ui->coursescmb->addItem(QString::number(id));
    }

}

setPrerequisites::~setPrerequisites()
{
    delete ui;
}

void setPrerequisites::on_backBTN_clicked()
{
    this->hide();
    adminPage *admin = new adminPage();
    admin->show();
    admin->updateCnt(uploadCourse::coursesCnt);
}


//unordered_map<int, Course>& courseTable
void setPrerequisites::on_setBtn_clicked()
{
    QString preTitle = ui->prerequisites_input->text();
    int preID = preTitle.toInt();
    QString courseid =ui->coursescmb->currentText();
    int id =courseid.toInt();

}
unordered_map<int, vector<int>>& setPrerequisites::getPrerequisitesTable(){
    static unordered_map<int, vector<int>> prerequisitesTable;
    return prerequisitesTable;
}



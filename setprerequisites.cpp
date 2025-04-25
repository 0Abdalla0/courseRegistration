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

}



setPrerequisites::~setPrerequisites()
{
    delete ui;
}

void setPrerequisites::on_pushButton_2_clicked()
{
    vector<int> programming_course;
    uploadCourse uc;
    unordered_map<int, Course> courseMap = uc.getCourseTable();
    unordered_map<int, Course>::iterator it = courseMap.begin();

    QString idString = ui->courseid_input->text();
    int id = idString.toInt();

    QString prereqString = ui->prerequisites_input->text();
    int prerequisitesId = idString.toInt();

    bool found = false;

    for (it = courseMap.begin(); it != courseMap.end(); ++it) {
        if (it->first == id) {
            found = true;
            if (it->first > 100 && it->first < 200) {
                if (programming_course.empty()) {
                    programming_course.push_back(prerequisitesId);
                    programming_course.push_back(id);
                }
            }
            break;
        }
    }
    cout<<prerequisitesId<<endl;
    cout<<id;
    if (!found) {
        QMessageBox::warning(this, "Invalid ID", "Please enter a valid course ID.");
        return;
    }
    vector<int>::iterator it_display=programming_course.begin();
    for(it_display; it_display != programming_course.end();it_display++){
        cout<<*it_display<<endl;
    }

}


//unordered_map<int, Course>& courseTable
void setPrerequisites::on_setBtn_clicked()
{
    cout<<"sdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

}



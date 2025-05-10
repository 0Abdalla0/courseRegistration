#include "generatereport.h"
#include "ui_generatereport.h"
#include "loginwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <unordered_map>
#include"mainwindow.h"
#include"managegrades.h"
#include "studentpage.h"
#include"grade.h"

generateReport::generateReport(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::generateReport)
{
    ui->setupUi(this);

    std = loginWindow::getSignedIn();
    std1 = manageGrades::getGrades();
    QString stdName = std.getName();
    QString stdIdStr = std.getId();
    int stdID = stdIdStr.toInt();
    QString stdGpaStr = std.getCgpa();

    // Set student info on UI labels
    ui->label->setText(stdName);
    ui->label_2->setText(stdGpaStr);
    ui->label_3->setText(stdIdStr);
    auto grades = std1;
    auto it = grades.begin();
    unordered_map<QString, grade*> innerUnMap;


    QVBoxLayout* layoutCourseName = new QVBoxLayout();
    QVBoxLayout* layoutId = new QVBoxLayout();
    QVBoxLayout* layoutGrades = new QVBoxLayout();
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        if(it->first==stdID)
        {
            innerUnMap=it->second;
            break;
        }
    }
    unordered_map<QString, grade*>::iterator it2;

    for(it2=innerUnMap.begin();it2!=innerUnMap.end();it2++)
    {
        qDebug() << "Number of students in grades map:" << it2->second;
        // int courseGrade = it->first;
        // QString courseGradeStr = QString::number(courseGrade);

        QLabel* labelCourseName = new QLabel(it2->first, this);
        layoutCourseName->addWidget(labelCourseName);
        ui->widgetCourseName->setLayout(layoutCourseName);
        QLabel* labelGrades = new QLabel(it2->second->courseGrade, this);
        layoutGrades->addWidget(labelGrades);
        ui->widgetGrades->setLayout(layoutGrades);
    }



}

generateReport::~generateReport()
{
    delete ui;
}

void generateReport::on_pushButton_clicked()
{
    this->hide();
    studentPage *stdPage = new studentPage;
    stdPage->show();
}


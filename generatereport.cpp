#include "generatereport.h"
#include "ui_generatereport.h"
#include "loginwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <unordered_map>
#include"mainwindow.h"
#include"managegrades.h"

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
    unordered_map<QString, QString> innerUnMap;


    QVBoxLayout* layout = new QVBoxLayout();
    for (auto it = grades.begin(); it != grades.end(); ++it) {
        if(it->first==stdID)
        {
         innerUnMap=it->second;
            break;
            }
        }
    unordered_map<QString, QString>::iterator it2;

    for(it2=innerUnMap.begin();it2!=innerUnMap.end();it2++)
    {
         qDebug() << "Number of students in grades map:" << it2->second;
    }

    //     int courseGrade = it->first;
    //     QString courseGradeStr = QString::number(courseGrade);

    //     QLabel* label = new QLabel(courseGradeStr, this);
    //     layout->addWidget(label);

    //  ui->widget->setLayout(layout);

}

generateReport::~generateReport()
{
    delete ui;
}

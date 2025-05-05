#include "viewgrades.h"
#include "ui_viewgrades.h"
#include "student.h"
#include "loginWindow.h"
#include <QDebug>
#include "managegrades.h"
viewGrades::viewGrades(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewGrades)
{
    ui->setupUi(this);
    std = loginWindow::getSignedIn();
    qDebug() << "std id is" << std.getId();

    int studentId = std.getId().toInt();

    const auto& allGrades = manageGrades::getGrades();

    auto it = allGrades.find(studentId);
    if (it != allGrades.end()) {
        const auto& studentCourses = it->second;
        for (const auto& [courseName, grade] : studentCourses) {
            ui->comboBox->addItem(courseName);
        }
    } else {
        qDebug() << "No grades found for student ID:" << studentId;
    }
}
void viewGrades::on_comboBox_currentIndexChanged(int index)
{

    QString selectedCourseName = ui->comboBox->itemText(index);
    int studentId = std.getId().toInt();

    const auto& allGrades = manageGrades::getGrades();
    auto it = allGrades.find(studentId);
    if (it != allGrades.end()) {
        const auto& studentCourses = it->second;
        auto courseIt = studentCourses.find(selectedCourseName);
        if (courseIt != studentCourses.end()) {
            QString grade = courseIt->second;
            ui->label->setText("Grade: " + grade);
            return;
        }
    }

    ui->label->setText("Grade not found.");
}

viewGrades::~viewGrades()
{
    delete ui;
}



// const map<int, QString>& grades = std.getGrades();
// if (grades.empty()) {
//     ui->listWidget->addItem("No grades available.");
// } else {
//     for (const auto& entry : grades) {
//         QString itemText = "Course ID: " + QString::number(entry.first) + " - Grade: " + entry.second;
//         ui->listWidget->addItem(itemText);
//     }
// }



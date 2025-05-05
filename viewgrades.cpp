#include "viewgrades.h"
#include "ui_viewgrades.h"
#include "student.h"
#include "loginWindow.h"
#include <QDebug>
viewGrades::viewGrades(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::viewGrades)
{
    ui->setupUi(this);
    std = loginWindow::getSignedIn();
    // Set demo grades for testing
    std.setGrades({
        {111, "A"},
        {112, "B"},
        {113, "C+"}
    });
    qDebug() << "std id is" << std.getId();
    for (auto& course :std.getGrades()) {
        ui->comboBox->addItem(QString::number(course.first));
    }
}
void viewGrades::on_comboBox_currentIndexChanged(int index)
{
    if (index < 0) return;

    // Get the selected course ID as a string, convert to int
    QString courseIdStr = ui->comboBox->itemText(index);
    int courseId = courseIdStr.toInt();

    // Look up the grade in the student's grades map
    const auto& grades = std.getGrades();
    auto it = grades.find(courseId);
    if (it != grades.end()) {
        QString grade = it->second;
        ui->label->setText("Grade: " + grade);
    } else {
        ui->label->setText("Grade not found.");
    }
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



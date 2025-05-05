#include "managegrades.h"
#include <QMessageBox>
#include "adminpage.h"
#include "mainwindow.cpp"
#include "student.h"
#include "ui_managegrades.h"
#include "uploadcourse.h"
#include <signup.h>
using namespace std;
manageGrades::manageGrades(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::manageGrades)
{
    ui->setupUi(this);
    uploadCourse uc;
    for (auto &student : MainWindow::getStudents()) {
        ui->studIdCmb->addItem(student.getId());
    }
    for (const auto &[id, course] : uc.getCourseTable()) {
        ui->courseNameCmb->addItem(course.getTitle());
    }
    vector<QString> grades = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D+", "D", "F"};
    for (unsigned long long var = 0; var < grades.size(); ++var) {
        ui->gradeCmb->addItem(grades[var]);
    }
}

manageGrades::~manageGrades()
{
    delete ui;
}

void manageGrades::on_backBtn_clicked()
{
    this->hide();
    adminPage *admin = new adminPage();
    admin->show();
}

void manageGrades::on_addGradeBtn_clicked()
{
    QString studentId = ui->studIdCmb->currentText();
    QString courseName = ui->courseNameCmb->currentText();
    QString gradeValue = ui->gradeCmb->currentText();
    manageGrades::getGrades()[studentId.toInt()][courseName] = gradeValue;
    QMessageBox::information(this, "Success", "GRADE HAS BEEN SUCCESSFULLY SUMBIITED");
}

map<int, unordered_map<QString, QString>> &manageGrades::getGrades()
{
    static map<int, unordered_map<QString, QString>> grades; // Corrected declaration
    return grades;
}

// Save all grades to CSV
void manageGrades::saveToCsv(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Could not open grades CSV for writing:" << filename;
        return;
    }

    QTextStream out(&file);
    out << "Student ID,Course Name,Grade\n";

    const auto &grades = manageGrades::getGrades();
    for (const auto &[stuId, courses] : grades) {
        for (const auto &[courseName, grade] : courses) {
            out << stuId << "," << courseName << "," << grade << "\n";
        }
    }

    file.close();
}
// Load all grades from CSV
void manageGrades::loadFromCsv(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open grades CSV for reading:" << filename;
        return;
    }

    QTextStream in(&file);
    QString header = in.readLine(); // skip header line

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() != 3)
            continue;

        bool ok;
        int stuId = parts[0].toInt(&ok);
        if (!ok)
            continue;

        QString courseName = parts[1];
        QString grade = parts[2];

        manageGrades::getGrades()[stuId][courseName] = grade;
    }

    file.close();
}

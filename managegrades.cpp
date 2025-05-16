#include "managegrades.h"
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFileDialog>
#include <QMessageBox>
#include <QMimeData>
#include <QString>
#include "adminpage.h"
#include "grade.h"
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
    vector<QString> semesters
        = {"First", "Second", "Third", "Fourth", "Fifth", "Sixth", "Seventh", "Eighth"};
    for (unsigned long long var = 0; var < semesters.size(); ++var) {
        ui->semesterCmb->addItem(semesters[var]);
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
    map<QString, double> gradeConverter = {{"A+", 4},
                                        {"A", 4},
                                        {"A-", 3.5},
                                        {"B+", 3},
                                        {"B", 2.5},
                                        {"B-", 2},
                                        {"C+", 1.5},
                                        {"C", 1.5},
                                        {"C-", 1},
                                        {"D+", 1},
                                        {"D", 1},
                                        {"F", 0.5}};
    QString studentId = ui->studIdCmb->currentText();
    QString courseName = ui->courseNameCmb->currentText();
    QString gradeValue = ui->gradeCmb->currentText();
    QString semester = ui->semesterCmb->currentText();
    double gpa = gradeConverter[gradeValue];
    grade *Grade = new grade(gradeValue, semester, gpa);
    manageGrades::getGrades()[studentId.toInt()][courseName] = Grade;

    QMessageBox::information(this, "Success", "GRADE HAS BEEN SUCCESSFULLY SUMBIITED");

}

map<int, unordered_map<QString, grade *>> &manageGrades::getGrades()
{
    static map<int, unordered_map<QString, grade *>> grades;
    return grades;
}
 map<QString, int> &manageGrades::getGradesConverter()
{
    static map<QString, int> gradeConverter;
    return gradeConverter;
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
    out << "Student ID,Course Name,Grade,Semester,GPA\n";

    const auto &grades = manageGrades::getGrades();
    for (const auto &[stuId, courses] : grades) {
        for (const auto &[courseName, grade] : courses) {
            out << stuId << "," << courseName << "," << grade->courseGrade << "," << grade->semester
                << "," << grade->gpa << "\n";
        }
    }

    file.close();
}

void manageGrades::loadFromCsv(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open grades CSV for reading:" << filename;
        return;
    }

    QTextStream in(&file);
    QString header = in.readLine();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");
        if (parts.size() != 5)
            continue;

        bool ok;
        int stuId = parts[0].toInt(&ok);
        if (!ok)
            continue;

        QString courseName = parts[1];
        QString gradeValue = parts[2];
        QString semester = parts[3];
        double gpa = parts[4].toDouble();
        grade *Grade = new grade(gradeValue, semester, gpa);
        manageGrades::getGrades()[stuId][courseName] = Grade;
    }

    file.close();
}

void manageGrades::on_uploadGradesBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Grades CSV",
                                                    "",
                                                    "CSV Files (*.csv)");
    if (!fileName.isEmpty()) {
        loadFromCsv(fileName);
        QMessageBox::information(this, "Success", "GRADE HAS BEEN SUCCESSFULLY SUMBIITED");
    }
}

void manageGrades::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls()) {
        QList<QUrl> urls = event->mimeData()->urls();
        if (!urls.isEmpty() && urls.first().toLocalFile().endsWith(".csv")) {
            event->acceptProposedAction();
        }
    }
}

void manageGrades::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (!urls.isEmpty()) {
        QString fileName = urls.first().toLocalFile();
        if (fileName.endsWith(".csv")) {
            loadFromCsv(fileName);
        }
    }
}

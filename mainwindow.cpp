#include "mainwindow.h"
#include <QCloseEvent>
#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSet>
#include "adminpage.h"
#include "managegrades.h"
#include "setprerequisites.h"
#include "ui_mainwindow.h"
#include "uploadcourse.h"
#include <student.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1366, 768);
}
void MainWindow::closeEvent(QCloseEvent *event)
{
    uploadCourse courses;
    setPrerequisites prerequisite;
    manageGrades grades;
    grades.saveToCsv("students'grades.csv");
    prerequisite.savePrerequisitesToFile("prerequisites");
    saveStudentsToFile();
    courses.saveCoursesToFile("courses.txt");

    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
    uploadCourse courses;
    setPrerequisites prerequisite;
    manageGrades grades;
    grades.saveToCsv("students'grades.csv");
    prerequisite.savePrerequisitesToFile("prerequisites.txt");
    saveStudentsToFile();
    courses.saveCoursesToFile("courses.txt");
    delete ui;
}

void MainWindow::on_registerbtn_windowIconChanged(const QIcon &icon) {}

void MainWindow::on_registerBtn_clicked()
{
    this->hide();
    signupWindow = new signup(this);
    signupWindow->show();
}
void MainWindow::loadUsersFromFile()
{
    adminPage *admin = new adminPage();
    QFile file("students.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to open file for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");

        if (parts.size() == 4) {
            student newStudent(parts[0], parts[1], parts[2], parts[3]);
            MainWindow::getStudents().append(newStudent);
            ++admin->studCnt;
        }
    }
    admin->updateStudCnt(admin->studCnt);
    file.close();
}

void MainWindow::saveStudentsToFile() const
{
    const_cast<MainWindow *>(this)->removeDuplicateStudents();
    QFile file("students.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);
    for (const student &stu : MainWindow::getStudents()) {
        out << stu.getName() << "," << stu.getId() << "," << stu.getCgpa() << ","
            << stu.getPassword()
            << "\n---------------------------------------------------------------------------------"
               "---------------\n";
    }
}

void MainWindow::removeDuplicateStudents()
{
    QSet<QString> seenIds;
    QVector<student> unique;
    unique.reserve(students.size());

    for (const student &s : MainWindow::getStudents()) {
        if (!seenIds.contains(s.getId())) {
            seenIds.insert(s.getId());
            unique.append(s);
        }
    }

    MainWindow::getStudents() = std::move(unique);
}

void MainWindow::on_signInBtn_clicked()
{
    this->hide();
    loginWin = new loginWindow(this);
    loginWin->show();
}
QList<student> &MainWindow::getStudents()
{
    static QList<student> students;
    return students;
}

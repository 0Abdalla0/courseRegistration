#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <student.h>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QDir>
#include <QCoreApplication>
#include <QSet>
#include <QCloseEvent>
#include"uploadcourse.h"
#include"setprerequisites.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1366, 768); // Set your desired width and height
}

void MainWindow::closeEvent(QCloseEvent *event) {
    uploadCourse courses;
    setPrerequisites prerequisite;
    prerequisite.savePrerequisitesToFile("prerequisites");
    saveStudentsToFile();
    courses.saveCoursesToFile("courses.txt");

    QMainWindow::closeEvent(event);
}

MainWindow::~MainWindow()
{
    uploadCourse courses;
    setPrerequisites prerequisite;
    prerequisite.savePrerequisitesToFile("prerequisites.txt");
    saveStudentsToFile();
    courses.saveCoursesToFile("courses.txt");
    delete ui;
}

void MainWindow::on_registerbtn_windowIconChanged(const QIcon &icon) {}

void MainWindow::on_registerBtn_clicked()
{
    this->hide();
    signupWindow = new signup(this, &students);
    signupWindow->show();
}

void MainWindow::loadUsersFromFile()
{
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
            students.append(newStudent);
        }
    }
    file.close();
}

void MainWindow::saveStudentsToFile() const
{
    const_cast<MainWindow*>(this)->removeDuplicateStudents();
    QFile file("students.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {return;}

    QTextStream out(&file);
    for (const student &stu : students) {
        out
            << stu.getName()     << ","
            << stu.getId()       << ","
            << stu.getCgpa()     << ","
            << stu.getPassword() << "\n------------------------------------------------------------------------------------------------\n";
    }
}

void MainWindow::removeDuplicateStudents()
{
    QSet<QString> seenIds;
    QVector<student> unique;
    unique.reserve(students.size());

    for (const student &s : students) {
        if (!seenIds.contains(s.getId())) {
            seenIds.insert(s.getId());
            unique.append(s);
        }
    }

    students = std::move(unique);
}

void MainWindow::on_signInBtn_clicked()
{
    this->hide();
    loginWin = new loginWindow(this, &students);
    loginWin->show();
}

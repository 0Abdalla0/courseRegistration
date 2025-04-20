#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<student.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1366, 768); // Set your desired width and height
    loadUsersFromFile();
}

MainWindow::~MainWindow()
{
    saveStudentsToFile();
    delete ui;
}




void MainWindow::on_registerbtn_windowIconChanged(const QIcon &icon)
{

}


void MainWindow::on_registerBtn_clicked()
{
    this->hide();
    signupWindow = new signup(this, &students);
    signupWindow->show();
}

void MainWindow::loadUsersFromFile() {
    QFile file("students.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to open file for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();  // Read a line from the file
        QStringList parts = line.split(",");  // Split the line by commas

        if (parts.size() == 4) {
            student newStudent(parts[0], parts[1], parts[2], parts[3]);
            students.append(newStudent);
        }
    }
    file.close();
}

void MainWindow::saveStudentsToFile() const {
    QFile file("students.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error: Unable to open file for writing.";
        return;  // If file can't be opened, return early
    }

    QTextStream out(&file);

    for (const student &stu : students) {
        out << stu.getName() << "," << stu.getId() << ","
            << stu.getCgpa() << "," << stu.getPassword() << "\n";
    }

    file.close();
}

void MainWindow::on_signInBtn_clicked()
{
    this->hide();
    loginWin = new loginWindow(this, &students);
    loginWin->show();
}


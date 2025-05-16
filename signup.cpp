#include "signup.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "adminpage.h"
#include "mainwindow.h"
#include "ui_signup.h"
signup::signup(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signup)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}
int signup::cnt = 0;
void signup::on_pushButton_2_clicked()
{
    adminPage *admin = new adminPage();
    QString name = ui->lineEdit_name->text();
    QString stdID = ui->lineEdit_id->text();
    QString cgpa = "0";
    QString password = ui->lineEdit_pass->text();
    QString confirmPassword = ui->lineEdit_confirmPass->text();

    if (name.isEmpty() || stdID.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Missing Info", "Please fill in all fields.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Password Error", "Passwords do not match.");
        return;
    }

    bool idExists = false;
    for (const student &s : MainWindow::getStudents()) {
        if (s.getId() == stdID) {
            QMessageBox::warning(this, "Duplicate", "A user with this ID already exists.");
            return;
        }
    }

    student newStudent(name, stdID, cgpa, password);
    MainWindow::getStudents().append(newStudent);
    signup::cnt++;
    admin->updateStudCnt(signup::cnt);
    QMessageBox::information(this, "Success", "Account created successfully!");

    ui->lineEdit_name->clear();
    ui->lineEdit_id->clear();
    ui->lineEdit_pass->clear();
    ui->lineEdit_confirmPass->clear();
    this->hide();
    loginWin = new loginWindow(this);
    loginWin->show();
}

void signup::on_pushButton_clicked()
{
    this->hide();
    loginWin = new loginWindow(this);
    loginWin->show();
}

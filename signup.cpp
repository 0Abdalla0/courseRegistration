#include "signup.h"
#include "ui_signup.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

signup::signup(QWidget *parent, QList<student>* studentList)
    : QDialog(parent), ui(new Ui::signup), students(studentList)
{
    ui->setupUi(this);
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString stdID = ui->lineEdit_id->text();
    QString cgpa = ui->lineEdit_gpa->text();
    QString password = ui->lineEdit_pass->text();
    QString confirmPassword = ui->lineEdit_confirmPass->text();

    if (name.isEmpty() || stdID.isEmpty() || cgpa.isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Missing Info", "Please fill in all fields.");
        return;
    }

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Password Error", "Passwords do not match.");
        return;
    }

    bool idExists = false;
    for (const student &s : *students) {
        if (s.getId() == stdID) {
            QMessageBox::warning(this, "Duplicate", "A user with this ID already exists.");
            return;
        }
    }

    student newStudent(name, stdID, cgpa, password);
    students->append(newStudent);

    QMessageBox::information(this, "Success", "Account created successfully!");

    ui->lineEdit_name->clear();
    ui->lineEdit_id->clear();
    ui->lineEdit_gpa->clear();
    ui->lineEdit_pass->clear();
    ui->lineEdit_confirmPass->clear();
    this->hide();
    loginWin = new loginWindow(this, students);
    loginWin->show();
}

void signup::on_pushButton_clicked()
{
    this->hide();
    loginWin = new loginWindow(this, students);
    loginWin->show();
}


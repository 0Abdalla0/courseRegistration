#include "loginwindow.h"
#include <QMessageBox>
#include "adminpage.h"
#include "studentpage.h"
#include "ui_loginwindow.h"
#include"mainwindow.h"
#include <signup.h>
loginWindow::loginWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}

void loginWindow::on_DontHaveBtn_clicked()
{
    this->hide();
    signup *signUpWin = new signup(this);
    signUpWin->show();
}

void loginWindow::on_SignInBtn_clicked()
{
    QString enteredID = ui->lineEdit_ID->text();
    QString enteredPassword = ui->lineEdit_pass->text();

    if (enteredID.isEmpty() || enteredPassword.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please enter both ID and password.");
        return;
    }

    bool userFound = false;
    for (const student &s :MainWindow::getStudents()) {
        if (s.getId() == enteredID) {
            userFound = true;
            if (s.getPassword() == enteredPassword) {
                QMessageBox::information(this,
                                         "Login Success",
                                         "Welcome back, " + s.getName() + "!");
                this->accept();
            } else {
                QMessageBox::warning(this, "Login Failed", "Incorrect password. Please try again.");
            }
            break;
        }
    }
    if (enteredID == "0" && enteredPassword == "admin") {
        this->hide();
        adminPage *admin = new adminPage();
        admin->show();
    } else if (!userFound) {
        QMessageBox::warning(this, "Login Failed", "No user found with the provided ID.");
    } else {
        this->hide();
        studentPage *stdPage = new studentPage();
        stdPage->show();
    }
}

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QList>
#include "student.h"
#include <loginwindow.h>

namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr, QList<student> *studentList = nullptr);
    ~signup();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::signup *ui;
    loginWindow *loginWin;
    QList<student> *students;
};

#endif

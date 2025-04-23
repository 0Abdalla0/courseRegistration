#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <student.h>

namespace Ui {
class loginWindow;
}

class loginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginWindow(QWidget *parent = nullptr, QList<student> *studentList = nullptr);
    ~loginWindow();

private slots:
    void on_DontHaveBtn_clicked();

    void on_SignInBtn_clicked();

private:
    Ui::loginWindow *ui;
    QList<student> *students;
};

#endif // LOGINWINDOW_H

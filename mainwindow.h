#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <loginwindow.h>
#include <signup.h>
#include <student.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QList<student> students;
    void loadUsersFromFile();
    void saveStudentsToFile() const;
    void removeDuplicateStudents();

private slots:
    void on_registerbtn_windowIconChanged(const QIcon &icon);

    void on_registerBtn_clicked();

    void on_signInBtn_clicked();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    signup *signupWindow;
    loginWindow *loginWin;
};
#endif // MAINWINDOW_H

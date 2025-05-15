#ifndef REGISTERCOURSE_H
#define REGISTERCOURSE_H

#include <QDialog>
#include <QString>
#include "course.h"
#include"student.h"
namespace Ui {
class registerCourse;
}

class registerCourse : public QDialog
{
    Q_OBJECT

public:
    explicit registerCourse(QWidget *parent = nullptr);
    ~registerCourse();
    static int regCnt;
    student stud;

private slots:
    void on_backBTN_clicked();
    void onCourseSelected(int row, int column);
    void on_registerBtn_clicked();
    void on_searchBtn_clicked();
    // unordered_map<int,registe
private:
    Ui::registerCourse *ui;
    int selectedCourseId = -1; // Track which course was selected
};

#endif // REGISTERCOURSE_H

#ifndef REGISTERCOURSE_H
#define REGISTERCOURSE_H

#include <QDialog>
#include <QString>
#include "course.h"
#include "student.h"
#include <unordered_map>
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
    static unordered_map<int, Course> registered;
    student stud;
    void loadFromFile(const QString &filename);
    void saveToFile(const QString &filename);
private slots:
    void on_backBTN_clicked();
    void onCourseSelected(int row, int column);
    void on_registerBtn_clicked();
    void on_searchBtn_clicked();

private:
    Ui::registerCourse *ui;
    int selectedCourseId = -1;
};

#endif // REGISTERCOURSE_H

#ifndef REGISTERCOURSE_H
#define REGISTERCOURSE_H

#include <QDialog>
#include <QString>
#include "course.h"

namespace Ui {
class registerCourse;
}

class registerCourse : public QDialog
{
    Q_OBJECT

public:
    explicit registerCourse(QWidget *parent = nullptr);
    ~registerCourse();

private slots:
    void on_backBTN_clicked();
    void onCourseSelected(int row, int column);
    void on_registerBtn_clicked();

private:
    Ui::registerCourse *ui;
    int selectedCourseId = -1; // Track which course was selected
};

#endif // REGISTERCOURSE_H

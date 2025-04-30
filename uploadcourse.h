#ifndef UPLOADCOURSE_H
#define UPLOADCOURSE_H
#include "course.h"
#include <QDialog>

namespace Ui {
class uploadCourse;
}

class uploadCourse : public QDialog
{
    Q_OBJECT

public:
    explicit uploadCourse(QWidget *parent = nullptr);
    ~uploadCourse();
    void saveCoursesToFile(const QString& filename);
    void loadCoursesFromFile(const QString& filename);
    static unordered_map<int, Course>& getCourseTable();
    static int coursesCnt;

private slots:

    void on_uploadBtn_clicked();

    void on_backBtn_clicked();

private:
    Ui::uploadCourse *ui;
};

#endif // UPLOADCOURSE_H

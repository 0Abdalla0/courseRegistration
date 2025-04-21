#ifndef UPLOADCOURSE_H
#define UPLOADCOURSE_H

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

private slots:

    void on_uploadBtn_clicked();

    void on_backBtn_clicked();

private:
    Ui::uploadCourse *ui;
};

#endif // UPLOADCOURSE_H

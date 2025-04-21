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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::uploadCourse *ui;
};

#endif // UPLOADCOURSE_H

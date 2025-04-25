#ifndef SETPREREQUISITES_H
#define SETPREREQUISITES_H
#include<unordered_map>
#include <QDialog>
#include"course.h"
namespace Ui {
class setPrerequisites;
}

class setPrerequisites : public QDialog
{
    Q_OBJECT

public:
    explicit setPrerequisites(QWidget *parent = nullptr);
    ~setPrerequisites();
    unordered_map<int,Course>* coursePtr;
    vector <int> programming_course ;


private slots:
    void on_pushButton_2_clicked();
    void on_setBtn_clicked();

private:
    Ui::setPrerequisites *ui;
    unordered_map<int, Course>* courses;
};

#endif // SETPREREQUISITES_H

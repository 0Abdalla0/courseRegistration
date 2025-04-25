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
    unordered_map<int, Course> courseMap;

    void on_setbtn_clicked(unordered_map<int, Course>& courseTable);

private slots:
    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_clicked(unordered_map<int, Course>& courseTable);

    void on_pushButton_clicked();

    void on_setbtn_clicked();

private:
    Ui::setPrerequisites *ui;
};

#endif // SETPREREQUISITES_H

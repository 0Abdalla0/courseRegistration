#ifndef CHECKPREREQUISITES_H
#define CHECKPREREQUISITES_H
#include <map>
#include <vector>
#include"course.h"

using namespace std;
#include <QDialog>

namespace Ui {
class checkprerequisites;
}

class checkprerequisites : public QDialog
{
    Q_OBJECT

public:
    explicit checkprerequisites(QWidget *parent = nullptr);
    ~checkprerequisites();
    map<int, vector<int>> prerequisitesTable;
    map<int, vector<int>>::iterator getPreit;
    unordered_map<int, Course> getCourseInfo;
    bool checkCourseValidation(int id);
    map<int, unordered_map<QString, QString>> gradesTabel;
private slots:
    void on_backBTN_clicked();

    void on_courseID_Cmb_currentIndexChanged(int index);

private:
    Ui::checkprerequisites *ui;
};

#endif // CHECKPREREQUISITES_H

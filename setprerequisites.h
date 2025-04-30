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
    static unordered_map<int, vector<int>>& getPrerequisitesTable();
    void savePrerequisitesToFile(const QString& filename);
    void loadPrerequisitesFromFile(const QString& filename);
private slots:
    void on_backBTN_clicked();
    void on_setBtn_clicked();

private:
    Ui::setPrerequisites *ui;
    unordered_map<int, Course>* courses;
};

#endif // SETPREREQUISITES_H

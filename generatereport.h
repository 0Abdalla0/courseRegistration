#ifndef GENERATEREPORT_H
#define GENERATEREPORT_H
#include <QDialog>
#include "grade.h"
#include "loginwindow.h"
#include"student.h"
namespace Ui {
class generateReport;
}

class generateReport : public QDialog
{
    Q_OBJECT

public:
    explicit generateReport(QWidget *parent = nullptr);
    map<int, unordered_map<QString, grade *>> std1;
    unordered_map<QString, grade *> innerUnMap;

    student std;
    map<int, unordered_map<QString, grade *>> grades;
    void calculate_CGPA();
    int stdID;
    static student& signedInStudent;
    map<QString, int>gradesConverter;
    ~generateReport();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    QString reportHtml();

private:
    Ui::generateReport *ui;
};

#endif // GENERATEREPORT_H

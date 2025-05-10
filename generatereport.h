#ifndef GENERATEREPORT_H
#define GENERATEREPORT_H
#include"loginwindow.h"
#include <QDialog>
#include"grade.h"
namespace Ui {
class generateReport;
}

class generateReport : public QDialog
{
    Q_OBJECT

public:
    explicit generateReport(QWidget *parent = nullptr);
    map<int, unordered_map<QString, grade*>> std1;
    student std;
    ~generateReport();

private slots:
    void on_pushButton_clicked();

private:
    Ui::generateReport *ui;
};

#endif // GENERATEREPORT_H

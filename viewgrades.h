#ifndef VIEWGRADES_H
#define VIEWGRADES_H
#include <QDialog>
#include "loginwindow.h"
#include "student.h"
namespace Ui {
class viewGrades;
}

class viewGrades : public QDialog
{
    Q_OBJECT

public:
    explicit viewGrades(QWidget *parent = nullptr);
    student std;

    ~viewGrades();
private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

private:
    Ui::viewGrades *ui;
};

#endif // VIEWGRADES_H

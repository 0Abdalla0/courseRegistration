#ifndef MANAGEGRADES_H
#define MANAGEGRADES_H

#include <QDialog>

namespace Ui {
class manageGrades;
}

class manageGrades : public QDialog
{
    Q_OBJECT

public:
    explicit manageGrades(QWidget *parent = nullptr);
    ~manageGrades();

private:
    Ui::manageGrades *ui;
};

#endif // MANAGEGRADES_H

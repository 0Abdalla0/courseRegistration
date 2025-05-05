#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H
#include "student.h"
#include <QDialog>

namespace Ui {
class studentPage;
}

class studentPage : public QDialog
{
    Q_OBJECT

public:
    explicit studentPage(QWidget *parent = nullptr );
    student signedIn;
    ~studentPage();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::studentPage *ui;
};

#endif // STUDENTPAGE_H

#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>

namespace Ui {
class adminPage;
}

class adminPage : public QDialog
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = nullptr);
    ~adminPage();
    void updateCnt(int &c);
    void updateStudCnt(int &c);
    int studCnt = 0;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_manageGrades_clicked();

private:
    Ui::adminPage *ui;
};

#endif // ADMINPAGE_H

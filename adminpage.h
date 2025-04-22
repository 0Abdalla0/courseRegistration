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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_textEdit_textChanged();

private:
    Ui::adminPage *ui;
};

#endif // ADMINPAGE_H

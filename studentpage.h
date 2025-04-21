#ifndef STUDENTPAGE_H
#define STUDENTPAGE_H

#include <QDialog>

namespace Ui {
class studentPage;
}

class studentPage : public QDialog
{
    Q_OBJECT

public:
    explicit studentPage(QWidget *parent = nullptr);
    ~studentPage();

private:
    Ui::studentPage *ui;
};

#endif // STUDENTPAGE_H

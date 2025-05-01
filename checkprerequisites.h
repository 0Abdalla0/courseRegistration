#ifndef CHECKPREREQUISITES_H
#define CHECKPREREQUISITES_H

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

private:
    Ui::checkprerequisites *ui;
};

#endif // CHECKPREREQUISITES_H

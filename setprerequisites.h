#ifndef SETPREREQUISITES_H
#define SETPREREQUISITES_H

#include <QDialog>

namespace Ui {
class setPrerequisites;
}

class setPrerequisites : public QDialog
{
    Q_OBJECT

public:
    explicit setPrerequisites(QWidget *parent = nullptr);
    ~setPrerequisites();

private:
    Ui::setPrerequisites *ui;
};

#endif // SETPREREQUISITES_H

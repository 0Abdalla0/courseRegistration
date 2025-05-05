#ifndef MANAGEGRADES_H
#define MANAGEGRADES_H
#include <QDialog>
#include <map>
#include <unordered_map>
using namespace std;
namespace Ui {
class manageGrades;
}

class manageGrades : public QDialog
{
    Q_OBJECT

public:
    explicit manageGrades(QWidget *parent = nullptr);
    ~manageGrades();
    static map<int, unordered_map<QString, QString>> &getGrades();
    static void saveToCsv(const QString &filename);
    static void loadFromCsv(const QString &filename);

private slots:
    void on_backBtn_clicked();

    void on_addGradeBtn_clicked();

private:
    Ui::manageGrades *ui;
};

#endif // MANAGEGRADES_H

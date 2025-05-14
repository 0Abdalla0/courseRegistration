#ifndef MANAGEGRADES_H
#define MANAGEGRADES_H
#include <QDialog>
#include <QDragEnterEvent>
#include <QDropEvent>
#include "grade.h"
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
    static map<int, unordered_map<QString, grade *>> &getGrades();
    static void saveToCsv(const QString &filename);
    static void loadFromCsv(const QString &filename);

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
private slots:
    void on_backBtn_clicked();

    void on_addGradeBtn_clicked();

    void on_uploadGradesBtn_clicked();

private:
    void processCSVFile(const QString &filePath);
    Ui::manageGrades *ui;
};

#endif // MANAGEGRADES_H

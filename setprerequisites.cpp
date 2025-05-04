#include "setprerequisites.h"
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include "adminPage.h"
#include "course.h"
#include "ui_setprerequisites.h"
#include "uploadcourse.h"
#include <stack>
#include <vector>
using namespace std;
setPrerequisites::setPrerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setPrerequisites)

{
    ui->setupUi(this);
    for (const auto &[id, course] : uploadCourse::getCourseTable()) {
        ui->coursescmb->addItem(QString::number(id));
    }
}

setPrerequisites::~setPrerequisites()
{
    delete ui;
}

void setPrerequisites::on_backBTN_clicked()
{
    this->hide();
    adminPage *admin = new adminPage();
    admin->show();
    admin->updateCnt(uploadCourse::coursesCnt);
}

void setPrerequisites::on_setBtn_clicked()
{
    QString preTitle = ui->prerequisites_input->text();
    bool isNumberPre;
    int preID = preTitle.toInt(&isNumberPre);

    QString courseid = ui->coursescmb->currentText();
    bool isNumberCourse;
    int id = courseid.toInt(&isNumberCourse);

    if (!isNumberPre || !isNumberCourse) {
        QMessageBox::warning(this, "Invalid input", "Course ID and prerequisite must be valid numbers.");
        return;
    }

    if (id == preID) {
        QMessageBox::warning(this, "Wrong input", "A course cannot be its own prerequisite.");
        return;
    }

    unordered_map<int,Course> courseTable = uploadCourse::getCourseTable();
    if (courseTable.find(id) == courseTable.end()) {
        QMessageBox::warning(this, "Invalid Course", "Selected course does not exist.");
        return;
    }
    if(preID == 0)
    {
         QMessageBox::warning(this, "NO Prerequisite ?", "You will not add prerequisite to this course ok?");
    }
    if (courseTable.find(preID) == courseTable.end() && preID!=0) {
        QMessageBox::warning(this, "Invalid Prerequisite", "Prerequisite course ID does not exist.");
        return;
    }

    if (std::find(setPrerequisites::getPrerequisitesTable()[id].begin(), setPrerequisites::getPrerequisitesTable()[id].end(), preID) != setPrerequisites::getPrerequisitesTable()[id].end()) {
        QMessageBox::information(this, "Duplicate", "This prerequisite is already added.");
        return;
    }

    // All checks passed
    setPrerequisites::getPrerequisitesTable()[id].push_back(preID);
    QMessageBox::information(this, "Success", "Prerequisite successfully set.");
}


map<int, vector<int>> &setPrerequisites::getPrerequisitesTable()
{
    static map<int, vector<int>> prerequisitesTable;
    return prerequisitesTable;
}
void setPrerequisites::savePrerequisitesToFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Could not open prerequisites file for writing.";
        return;
    }

    QTextStream out(&file);

    // For each course with prerequisites...
    for (const auto &[courseId, preList] : setPrerequisites::getPrerequisitesTable()) {
        if (preList.empty())
            continue; // skip courses with no prerequisites

        // Write the course ID...
        out << courseId;

        // ...then each prereq ID, comma-separated
        for (unsigned long long i = 0; i < preList.size(); ++i) {
            out << "," << preList[i];
        }

        // End with a separator line (same style as your courses file)
        out << "\n-----------------------------------------------------------------\n";
    }

    file.close();
}
void setPrerequisites::loadPrerequisitesFromFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        // Skip separator lines
        if (line.startsWith("-") || line.isEmpty())
            continue;

        QStringList parts = line.split(",");

        if (parts.size() >= 2) {
            int courseId = parts[0].toInt();
            for (int i = 1; i < parts.size(); ++i) {
                int preId = parts[i].toInt();
                getPrerequisitesTable()[courseId].push_back(preId);
            }
        }
    }
    file.close();
}

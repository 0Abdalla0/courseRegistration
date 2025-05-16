#include "setprerequisites.h"
#include "ui_setprerequisites.h"

#include "adminPage.h"
#include "course.h"
#include "uploadcourse.h"

#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

#include <unordered_map>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

setPrerequisites::setPrerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setPrerequisites)
{
    ui->setupUi(this);

    // Populate coursescmb with course titles
    for (const auto &[id, course] : uploadCourse::getCourseTable()) {
        ui->coursescmb->addItem(course.getTitle());
    }

    // Connect course combo change signal to update prerequisites combo
    connect(ui->coursescmb, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &setPrerequisites::onCourseChanged);

    // Trigger initial population
    onCourseChanged(0);
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
    QString courseName = ui->coursescmb->currentText();
    int courseID = -1;

    for (const auto &[id, course] : uploadCourse::getCourseTable()) {
        if (courseName == course.getTitle()) {
            courseID = id;
            break;
        }
    }

    if (!isNumberPre) {
        QMessageBox::warning(this, "Invalid input", "Course ID and prerequisite must be valid numbers.");
        return;
    }

    if (courseID == preID) {
        QMessageBox::warning(this, "Wrong input", "A course cannot be its own prerequisite.");
        return;
    }

    unordered_map<int, Course> courseTable = uploadCourse::getCourseTable();
    if (courseTable.find(courseID) == courseTable.end()) {
        QMessageBox::warning(this, "Invalid Course", "Selected course does not exist.");
        return;
    }

    if (std::find(setPrerequisites::getPrerequisitesTable()[courseID].begin(),
                  setPrerequisites::getPrerequisitesTable()[courseID].end(),
                  preID)
        != setPrerequisites::getPrerequisitesTable()[courseID].end()) {
        QMessageBox::information(this, "Duplicate", "This prerequisite is already added.");
        return;
    }

    // All checks passed
    setPrerequisites::getPrerequisitesTable()[courseID].push_back(preID);
    QMessageBox::information(this, "Success", "Prerequisite successfully set.");
}

void setPrerequisites::on_removeBtn_clicked()
{
    QString selectedCourseName = ui->coursescmb->currentText();
    QString selectedPreTitle = ui->preCmb->currentText();

    int selectedCourseID = -1;
    int selectedPreID = -1;

    const auto &courseTable = uploadCourse::getCourseTable();

    for (const auto &[id, course] : courseTable) {
        if (course.getTitle() == selectedCourseName) {
            selectedCourseID = id;
        }
        if (course.getTitle() == selectedPreTitle) {
            selectedPreID = id;
        }
    }

    if (selectedCourseID == -1 || selectedPreID == -1) {
        QMessageBox::warning(this, "Error", "Failed to resolve course or prerequisite.");
        return;
    }

    auto &preList = getPrerequisitesTable()[selectedCourseID];
    auto it = std::find(preList.begin(), preList.end(), selectedPreID);
    if (it != preList.end()) {
        preList.erase(it);
        QMessageBox::information(this, "Removed", "Prerequisite removed.");
    } else {
        QMessageBox::information(this, "Not Found", "Selected prerequisite not found.");
    }
}

void setPrerequisites::onCourseChanged(int)
{
    QString selectedCourseName = ui->coursescmb->currentText();
    int selectedCourseID = -1;

    const auto &courseTable = uploadCourse::getCourseTable();
    ui->preCmb->clear();

    for (const auto &[id, course] : courseTable) {
        if (course.getTitle() == selectedCourseName) {
            selectedCourseID = id;
            break;
        }
    }

    for (const auto &[id, course] : courseTable) {
        if (id != selectedCourseID) {
            ui->preCmb->addItem(course.getTitle());
        }
    }
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

    for (const auto &[courseId, preList] : setPrerequisites::getPrerequisitesTable()) {
        if (preList.empty())
            continue;
        out << courseId;
        for (unsigned long long i = 0; i < preList.size(); ++i) {
            out << "," << preList[i];
        }
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

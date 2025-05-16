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
    QString courseName = ui->coursescmb->currentText();
    QString prereqName = ui->preCmb->currentText();

    if (courseName == prereqName) {
        QMessageBox::warning(this, "Wrong input", "A course cannot be its own prerequisite.");
        return;
    }

    int courseID = -1;
    int prereqID = -1;

    const auto &courseTable = uploadCourse::getCourseTable();

    for (const auto &[id, course] : courseTable) {
        if (course.getTitle() == courseName) {
            courseID = id;
        }
        if (course.getTitle() == prereqName) {
            prereqID = id;
        }
    }

    if (courseID == -1 || prereqID == -1) {
        QMessageBox::warning(this, "Invalid Course", "Failed to resolve course or prerequisite.");
        return;
    }

    // Check if this prerequisite name is already in the list by comparing course names
    const auto &prereqList = getPrerequisitesTable()[courseID];
    for (int id : prereqList) {
        if (courseTable.at(id).getTitle() == prereqName) {
            QMessageBox::information(this, "Duplicate", "This prerequisite is already added.");
            return;
        }
    }

    // All checks passed
    getPrerequisitesTable()[courseID].push_back(prereqID);
    QMessageBox::information(this, "Success", "Prerequisite successfully set.");
    onCourseChanged(0);
}


void setPrerequisites::on_removeBtn_clicked()
{
    QString selectedCourseName = ui->coursescmb->currentText();
    QString selectedPreTitle = ui->preCmb->currentText();

    // Remove marker if present (e.g., " ✓")
    selectedPreTitle = selectedPreTitle.remove(" ✓");  // Or whatever marker you used

    int selectedCourseID = -1;
    int selectedPreID = -1;

    const auto &courseTable = uploadCourse::getCourseTable();

    // Get course IDs
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

    // Find and remove prerequisite
    auto &preList = getPrerequisitesTable()[selectedCourseID];
    auto it = std::find(preList.begin(), preList.end(), selectedPreID);

    if (it != preList.end()) {
        preList.erase(it);
        QMessageBox::information(this, "Removed", "Prerequisite removed.");
        onCourseChanged(0);  // Refresh the preCmb display with updated markers
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

    // Get ID of the selected course
    for (const auto &[id, course] : courseTable) {
        if (course.getTitle() == selectedCourseName) {
            selectedCourseID = id;
            break;
        }
    }

    // Get the current prerequisite list
    const auto &prereqTable = getPrerequisitesTable();
    const auto &currentPrereqs = prereqTable.find(selectedCourseID) != prereqTable.end()
                                     ? prereqTable.at(selectedCourseID)
                                     : vector<int>();

    // Add all other courses to the preCmb
    for (const auto &[id, course] : courseTable) {
        if (id == selectedCourseID)
            continue;

        QString displayTitle = course.getTitle();

        // If this course is already a prerequisite, append a marker
        if (std::find(currentPrereqs.begin(), currentPrereqs.end(), id) != currentPrereqs.end()) {
            displayTitle += " ✓";  // or " (Already prerequisite)"
        }

        ui->preCmb->addItem(displayTitle);
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
    const auto &courseTable = uploadCourse::getCourseTable();

    for (const auto &[courseId, preList] : getPrerequisitesTable()) {
        if (preList.empty())
            continue;

        QString courseTitle = courseTable.at(courseId).getTitle();
        out << courseTitle;

        for (int preId : preList) {
            QString preTitle = courseTable.at(preId).getTitle();
            out << "," << preTitle;
        }

        out << "\n------------------------------------------------------\n";
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
    const auto &courseTable = uploadCourse::getCourseTable();

    // Build title-to-ID lookup map
    QMap<QString, int> titleToId;
    for (const auto &[id, course] : courseTable) {
        titleToId[course.getTitle()] = id;
    }

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.startsWith("-") || line.isEmpty())
            continue;

        QStringList parts = line.split(",");
        if (parts.size() >= 2) {
            QString courseTitle = parts[0];
            if (!titleToId.contains(courseTitle)) continue;

            int courseId = titleToId[courseTitle];

            for (int i = 1; i < parts.size(); ++i) {
                QString preTitle = parts[i];
                if (!titleToId.contains(preTitle)) continue;

                int preId = titleToId[preTitle];
                getPrerequisitesTable()[courseId].push_back(preId);
            }
        }
    }

    file.close();
}

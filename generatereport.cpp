#include "generatereport.h"
#include "ui_generatereport.h"
#include "loginwindow.h"
#include "managegrades.h"
#include "uploadcourse.h"
#include "studentpage.h"

#include <QDebug>
#include <QDesktopServices>
#include <QDir>
#include <QFile>
#include <QLabel>
#include <QStandardPaths>
#include <QTextDocument>
#include <QUrl>
#include <QVBoxLayout>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

generateReport::generateReport(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::generateReport),
    std(loginWindow::getSignedIn()), // Initialize reference
    stdID(0)
{
    ui->setupUi(this);

    QString stdIdStr = std.getId();
    bool ok;
    stdID = stdIdStr.toInt(&ok);
    if (!ok) {
        qWarning() << "Invalid student ID format:" << stdIdStr;
        stdID = 0;
    }

    // Calculate CGPA first
    calculate_CGPA();

    // Get other student data
    std1 = manageGrades::getGrades();
    gradesConverter = manageGrades::getGradesConverter();

    QString stdName = std.getName();

    // Set student info on UI (now with updated CGPA)
    ui->label->setText(stdName);
    ui->label_2->setText(std.getCgpa()); // Now shows updated CGPA
    ui->label_3->setText(stdIdStr);

    // Setup grade display layouts
    QVBoxLayout *layoutCourseName = new QVBoxLayout();
    QVBoxLayout *layoutGrades = new QVBoxLayout();
    QVBoxLayout *layoutSemester = new QVBoxLayout();

    // Find grades for this student
    auto it = std1.find(stdID);
    if (it != std1.end()) {
        innerUnMap = it->second;

        for (const auto &[courseName, gradeObj] : innerUnMap) {
            if (!gradeObj) continue;

            // Add course name
            QLabel *labelCourseName = new QLabel(courseName, this);
            layoutCourseName->addWidget(labelCourseName);

            // Add grade
            QLabel *labelGrades = new QLabel(gradeObj->courseGrade, this);
            layoutGrades->addWidget(labelGrades);

            // Add semester
            QLabel *labelSemester = new QLabel(gradeObj->semester, this);
            layoutSemester->addWidget(labelSemester);
        }
    } else {
        qWarning() << "No grades found for student ID:" << stdID;
    }

    // Set layouts
    ui->widgetCourseName->setLayout(layoutCourseName);
    ui->widgetGrades->setLayout(layoutGrades);
    ui->widgetSemster->setLayout(layoutSemester);
}

generateReport::~generateReport()
{
    delete ui;
}

void generateReport::calculate_CGPA()
{
    double totalGradePoints = 0.0;
    int totalCreditHours = 0;

    auto gradesMap = manageGrades::getGrades();
    auto &courseTable = uploadCourse::getCourseTable();

    if (gradesMap.find(stdID) == gradesMap.end()) {
        qDebug() << "No grades found for student ID:" << stdID;
        std.setCgpa("0.00");
        return;
    }

    const auto &studentGrades = gradesMap[stdID];

    // Create course title to credit hours map
    std::unordered_map<QString, int> titleToCredits;
    for (const auto &[id, course] : courseTable) {
        titleToCredits[course.getTitle()] = course.getCreditHours();
    }

    for (const auto &[courseName, gradeObj] : studentGrades) {
        if (!gradeObj) continue;

        auto it = titleToCredits.find(courseName);
        if (it == titleToCredits.end()) {
            qWarning() << "Credit hours not found for course:" << courseName;
            continue;
        }

        int creditHours = it->second;
        totalGradePoints += gradeObj->gpa * creditHours;
        totalCreditHours += creditHours;
    }

    if (totalCreditHours == 0) {
        qDebug() << "No valid credit hours found.";
        std.setCgpa("0.00");
        return;
    }

    double cgpaValue = totalGradePoints / totalCreditHours;
    std.setCgpa(QString::number(cgpaValue, 'f', 2));
    qDebug() << "CGPA Calculated:" << std.getCgpa() << "for student:" << std.getId();
}

void generateReport::on_pushButton_clicked()
{
    this->hide();
    studentPage *stdPage = new studentPage;
    stdPage->show();
}

QString generateReport::reportHtml()
{
    // Refresh CGPA before report generation
    calculate_CGPA();

    QString html =
        "<html>"
        "<head><style>"
        "body { font-family: Arial; margin: 20px; }"
        "h2 { color: #2c3e50; }"
        "table { border-collapse: collapse; width: 100%; margin-top: 20px; }"
        "th { background-color: #3498db; color: white; text-align: left; }"
        "td, th { border: 1px solid #ddd; padding: 8px; }"
        "tr:nth-child(even) { background-color: #f2f2f2; }"
        "</style></head>"
        "<body>"
        "<h2 align='center'>Student Grade Report</h2>"
        "<p><b>Name:</b> " + std.getName() +
        " &nbsp;&nbsp; <b>ID:</b> " + std.getId() +
        " &nbsp;&nbsp; <b>CGPA:</b> " + std.getCgpa() + "</p>"
                                                        "<table>"
                                                        "<tr><th>Course</th><th>Grade</th><th>Semester</th></tr>";

    double sum = 0;
    int count = 0;
    for (const auto &[course, gradeObj] : innerUnMap) {
        if (!gradeObj) continue;

        bool ok;
        double gr = gradeObj->courseGrade.toDouble(&ok);
        if (ok) {
            sum += gr;
            ++count;
        }

        html += "<tr>"
                "<td>" + course + "</td>"
                           "<td align='center'>" + gradeObj->courseGrade + "</td>"
                                          "<td>" + gradeObj->semester + "</td>"
                                       "</tr>";
    }

    html += "</table>";

    if (count > 0) {
        double overall = sum / count;
        html += "<p><b>Overall GPA:</b> " + QString::number(overall, 'f', 2) + "</p>";
    }

    html += "</body></html>";
    return html;
}

void generateReport::on_pushButton_2_clicked()
{
    QString html = reportHtml();

    // Optionally refresh CGPA label in UI after re-calculation
    ui->label_2->setText(std.getCgpa());

    QString tmpDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
    if (tmpDir.isEmpty()) {
        tmpDir = QDir::homePath();
    }

    QString filePath = tmpDir + QDir::separator() + "student_report_" + std.getId() + ".html";

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Could not write report to" << filePath;
        return;
    }

    QTextStream out(&file);
    out << html;
    file.close();

    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

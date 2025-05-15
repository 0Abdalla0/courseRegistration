#include "generatereport.h"
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include "grade.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "managegrades.h"
#include "studentpage.h"
#include "ui_generatereport.h"
#include <iostream>
#include <unordered_map>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPageSize>
#include <QPageLayout>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QDesktopServices>
#include <QUrl>
#include <QTextDocument>
using namespace std;

generateReport::generateReport(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::generateReport)
{
    ui->setupUi(this);

    std = loginWindow::getSignedIn();
    std1 = manageGrades::getGrades();
    QString stdName = std.getName();
    QString stdIdStr = std.getId();
    int stdID = stdIdStr.toInt();
    QString stdGpaStr = std.getCgpa();

    // Set student info on UI labels
    ui->label->setText(stdName);
    ui->label_2->setText(stdGpaStr);
    ui->label_3->setText(stdIdStr);
    auto grades = std1;
    auto it = grades.begin();
    // unordered_map<QString, grade *> innerUnMap;

    qDebug() << "first -----> (1) " << it->second.begin()->first << "\n";
    qDebug() << "first -----> (2) " << it->second.begin()->second->semester << "\n";
    qDebug() << "second -----> " << it->first << "\n";

    QVBoxLayout *layoutCourseName = new QVBoxLayout();

    QVBoxLayout *layoutId = new QVBoxLayout();

    QVBoxLayout *layoutGrades = new QVBoxLayout();

    QVBoxLayout *layoutSemester = new QVBoxLayout();

    for (auto it = grades.begin(); it != grades.end(); ++it) {
        if (it->first == stdID) {
            innerUnMap = it->second;
            qDebug() << innerUnMap.begin()->first << "\n";
            qDebug() << innerUnMap.begin()->second->semester << "\n";
            break;
        }
    }

    unordered_map<QString, grade *>::iterator it2;

    for (it2 = innerUnMap.begin(); it2 != innerUnMap.end(); it2++) {
        qDebug() << "Number of students in grades map:" << it2->second;
        // int courseGrade = it->first;
        // QString courseGradeStr = QString::number(courseGrade);

        QLabel *labelCourseName = new QLabel(it2->first, this);
        layoutCourseName->addWidget(labelCourseName);
        ui->widgetCourseName->setLayout(layoutCourseName);
        QLabel *labelGrades = new QLabel(it2->second->courseGrade, this);
        layoutGrades->addWidget(labelGrades);
        ui->widgetGrades->setLayout(layoutGrades);
        QLabel *labelSemester = new QLabel(it2->second->semester, this);
        layoutSemester->addWidget(labelSemester);
        ui->widgetSemster->setLayout(layoutSemester);
    }
}

generateReport::~generateReport()
{
    delete ui;
}

void generateReport::on_pushButton_clicked()
{
    this->hide();
    studentPage *stdPage = new studentPage;
    stdPage->show();
}

QString generateReport::reportHtml()
{
    QString html =
        "<h2 align='center'>Student Grade Report</h2>"
        "<p><b>Name:</b> " + std.getName() +
        "    <b>ID:</b> " + std.getId() +
        "    <b>CGPA:</b> " + std.getCgpa() +
        "</p>"
        "<table border='1' cellspacing='0' cellpadding='6'>"
        "<tr><th>Course</th><th>Grade</th><th>Semester</th></tr>";


    double sum = 0;
    int count = 0;
    for (auto &p : innerUnMap) {
        const QString &course = p.first;
        const grade *g = p.second;
        bool ok;
        double gr = g->courseGrade.toDouble(&ok);
        if (ok) { sum += gr; ++count; }
        html += "<tr>"
                "<td>" + course + "</td>"
                           "<td align='center'>" + g->courseGrade + "</td>"
                                   "<td>" + g->semester + "</td>"
                                "</tr>";
    }
    html += "</table>";
    double overall = count ? (sum / count) : 0.0;
    html += "<p><b>Overall GPA:</b> "
            + QString::number(overall, 'f', 2)
            + "</p>";
    return html;
}

void generateReport::on_pushButton_2_clicked()
{
    QString html = reportHtml();

    QString tmpDir = QStandardPaths::writableLocation(
        QStandardPaths::TempLocation);
    if (tmpDir.isEmpty())
        tmpDir = QDir::homePath();   // fallback

    QString filePath = tmpDir + QDir::separator() +
                       "student_report.html";

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


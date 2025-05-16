#include "registercourse.h"
#include <QFont>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "adminpage.h"
#include "checkprerequisites.h"
#include "loginwindow.h"
#include "studentpage.h"
#include "ui_registercourse.h"
#include "uploadcourse.h"
#include <unordered_map>

registerCourse::registerCourse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerCourse)
{
    ui->setupUi(this);

    unordered_map<int, Course> &courseTable = uploadCourse::getCourseTable();
    ui->titleItem->setColumnCount(3);
    ui->titleItem->setHorizontalHeaderLabels(QStringList() << "ID" << "Title" << "Credit Hours");
    ui->titleItem->setRowCount(static_cast<int>(courseTable.size()));
    ui->titleItem->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->titleItem->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->titleItem->setEditTriggers(QAbstractItemView::NoEditTriggers);

    QFont font = ui->titleItem->font();
    font.setPointSize(12);
    ui->titleItem->setFont(font);

    int row = 0;
    for (const auto &[id, course] : courseTable) {
        ui->titleItem->setItem(row, 0, new QTableWidgetItem(QString::number(course.getId())));
        ui->titleItem->setItem(row, 1, new QTableWidgetItem(course.getTitle()));
        ui->titleItem->setItem(row,
                               2,
                               new QTableWidgetItem(QString::number(course.getCreditHours())));
        ui->titleItem->setRowHeight(row, 30);
        row++;
    }

    ui->titleItem->setStyleSheet("QTableWidget {"
                                 "   background-color: white;"
                                 "   color: black;"
                                 "   gridline-color: #e0e0e0;"
                                 "border:none"
                                 "}"
                                 "QTableWidget QTableCornerButton::section {"
                                 "   background: #f5f5f5;"
                                 "   border: 1px solid #e0e0e0;"
                                 "}"
                                 "QHeaderView::section {"
                                 "   background-color: #f5f5f5;"
                                 "   color: black;"
                                 "   padding: 5px;"
                                 "   border: none;"
                                 "   min-width: 100px;"
                                 "   border-bottom: 2px solid #e0e0e0;"
                                 "}"
                                 "QTableWidget::item {"
                                 "   border-bottom: 1px solid #f0f0f0;"
                                 "}");

    for (int col = 0; col < 4; ++col) {
        ui->titleItem->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
    }

    // Center-align numeric columns
    for (int row = 0; row < ui->titleItem->rowCount(); ++row) {
        for (int col : {0, 1, 3}) { // Columns #, ID, and Credit Hours
            if (auto item = ui->titleItem->item(row, col)) {
                item->setTextAlignment(Qt::AlignCenter);
            }
        }
    }

    ui->titleItem->resizeColumnsToContents();
    ui->titleItem->verticalHeader()->setStretchLastSection(true);
    ui->titleItem->horizontalHeader()->setStretchLastSection(false);
    ui->titleItem->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    connect(ui->titleItem, &QTableWidget::cellClicked, this, &registerCourse::onCourseSelected);
}
unordered_map<int, Course> registerCourse::registered;

registerCourse::~registerCourse()
{
    delete ui;
}
int registerCourse::regCnt = 0;
void registerCourse::onCourseSelected(int row, int column)
{
    QTableWidgetItem *idItem = ui->titleItem->item(row, 0);
    if (idItem) {
        selectedCourseId = idItem->text().toInt();
    }
}

void registerCourse::on_registerBtn_clicked()
{
    qDebug() << registered.size();
    adminPage *admin = new adminPage();
    if (selectedCourseId == -1) {
        QMessageBox::warning(this, "No Course Selected", "Please select a course to register.");
        return;
    }
    bool alreadyRegistered = false;
    const auto &courseTable = uploadCourse::getCourseTable();
    auto it = courseTable.find(selectedCourseId);
    checkprerequisites *checker = new checkprerequisites();
    stud = loginWindow::getSignedIn();
    int studentId = stud.getId().toInt();
    bool prerequisitesCompleted = checker->checkCourseValidation(selectedCourseId, studentId);

    for (const auto [studId, courseIt] : registered) {
        if (studId == studentId && courseIt.getId() == selectedCourseId) {
            QMessageBox::warning(
                this,
                "Error",
                "The course you are trying to register you already registered before");
            alreadyRegistered = true;
            break;
        }
    }
    if (it != courseTable.end() && prerequisitesCompleted && !alreadyRegistered) {
        const Course &course = it->second;

        QMessageBox::information(this,
                                 "Registration Successful",
                                 "You have registered for:\n" + course.getTitle()
                                     + "\nCredit Hours: "
                                     + QString::number(course.getCreditHours()));
        registerCourse::regCnt++;
        admin->updateRegistrationsCnt(registerCourse::regCnt);
        registered[studentId] = course;

    } else {
        if (prerequisitesCompleted == false)
            QMessageBox::warning(this,
                                 "Error",
                                 "You did not complete the prerequisites of this course.");
        else
            QMessageBox::warning(this, "Error", "Selected course not found.");
    }
}

void registerCourse::on_backBTN_clicked()
{
    this->hide();
    studentPage *stud = new studentPage();
    stud->show();
}

void registerCourse::on_searchBtn_clicked()
{
    QString courseName = ui->searchText->text();
    bool found = false;
    unordered_map<int, Course> &courseTable = uploadCourse::getCourseTable();
    int courseId;
    Course courseToBeDisplayed;
    unordered_map<int, Course> coursesToBeDisplayed;
    unordered_map<int, Course> searchCourse;
    unordered_map<int, Course>::iterator it = courseTable.begin();

    while (it != courseTable.end()) {
        const QString &title = it->second.getTitle();
        if (title.contains(courseName, Qt::CaseInsensitive)) {
            found = true;
            coursesToBeDisplayed.insert(*it);
        }
        it++;
    }

    if (!found) {
        QMessageBox::warning(this, "No Course Selected", "course not found");
    } else {
        ui->titleItem->clearContents();
        ui->titleItem->setRowCount(coursesToBeDisplayed.size());

        unordered_map<int, Course>::iterator it2 = coursesToBeDisplayed.begin();

        int row = 0;
        while (it2 != coursesToBeDisplayed.end()) {
            ui->titleItem->setItem(row, 0, new QTableWidgetItem(QString::number(it2->first)));
            ui->titleItem->setItem(row, 1, new QTableWidgetItem(it2->second.getTitle()));
            ui->titleItem->setItem(row,
                                   2,
                                   new QTableWidgetItem(
                                       QString::number(it2->second.getCreditHours())));
            ui->titleItem->setRowHeight(row, 10);
            it2++;
            row++;
        }
    }
}

void registerCourse ::saveToFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Could not open file for writing.";
        return;
    }

    QTextStream out(&file);
    for (const auto &[studId, course] : registerCourse::registered) {
        out << studId << "," << course.getId() << "," << course.getTitle() << ","
            << course.getInstructorName() << "," << course.getInstructorEmail() << ","
            << course.getSyllabus() << "," << course.getCreditHours()
            << "\n-----------------------------------------------------------------\n";
    }

    file.close();
}
void registerCourse ::loadFromFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file for reading.";
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        QStringList parts = line.split(",");

        if (parts.size() == 6) {
            int studId = parts[0].toInt();
            int courseId = parts[1].toInt();
            QString name = parts[2];
            QString instName = parts[3];
            QString instEmail = parts[4];
            QString syllabus = parts[5];
            int credit = parts[6].toInt();

            Course course(courseId, name, instName, instEmail, syllabus, credit);
            registerCourse::registered[studId] = course;
            registerCourse::regCnt++;
        }
    }

    file.close();
}

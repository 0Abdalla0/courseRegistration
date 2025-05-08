#include "registercourse.h"
#include "ui_registercourse.h"
#include "studentpage.h"
#include "uploadcourse.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFont>
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
        ui->titleItem->setItem(row, 2, new QTableWidgetItem(QString::number(course.getCreditHours())));
        ui->titleItem->setRowHeight(row, 30);
        row++;
    }

    ui->titleItem->resizeColumnsToContents();
    ui->titleItem->horizontalHeader()->setStretchLastSection(true);

    connect(ui->titleItem, &QTableWidget::cellClicked,
            this, &registerCourse::onCourseSelected);
}

registerCourse::~registerCourse()
{
    delete ui;
}

void registerCourse::onCourseSelected(int row, int column)
{
    QTableWidgetItem *idItem = ui->titleItem->item(row, 0);
    if (idItem) {
        selectedCourseId = idItem->text().toInt();
    }
}

void registerCourse::on_registerBtn_clicked()
{
    if (selectedCourseId == -1) {
        QMessageBox::warning(this, "No Course Selected", "Please select a course to register.");
        return;
    }

    const auto &courseTable = uploadCourse::getCourseTable();
    auto it = courseTable.find(selectedCourseId);

    if (it != courseTable.end()) {
        const Course &course = it->second;
        // TODO: Save to student course list (if needed)
        QMessageBox::information(this, "Registration Successful",
                                 "You have registered for:\n" +
                                     course.getTitle() + "\nCredit Hours: " +
                                     QString::number(course.getCreditHours()));
    } else {
        QMessageBox::warning(this, "Error", "Selected course not found.");
    }
}

void registerCourse::on_backBTN_clicked()
{
    this->hide();
    studentPage *stud = new studentPage();
    stud->show();
}

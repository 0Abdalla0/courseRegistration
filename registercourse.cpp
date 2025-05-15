#include "registercourse.h"
#include <QFont>
#include <QMessageBox>
#include <QTableWidgetItem>
#include "adminpage.h"
#include "studentpage.h"
#include "ui_registercourse.h"
#include "uploadcourse.h"
#include <unordered_map>
#include "checkprerequisites.h"
registerCourse::registerCourse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerCourse)
{
    ui->setupUi(this);

    unordered_map<int,Course> &courseTable = uploadCourse::getCourseTable();

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

    ui->titleItem->setStyleSheet(
        "QTableWidget {"
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
        "}"
        );



    for (int col = 0; col < 4; ++col) {
        ui->titleItem->horizontalHeader()->setSectionResizeMode(col, QHeaderView::Stretch);
    }

    // Center-align numeric columns
    for (int row = 0; row < ui->titleItem->rowCount(); ++row) {
        for (int col : {0, 1, 3}) {  // Columns #, ID, and Credit Hours
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
    adminPage *admin = new adminPage();
    if (selectedCourseId == -1) {
        QMessageBox::warning(this, "No Course Selected", "Please select a course to register.");
        return;
    }

    const auto &courseTable = uploadCourse::getCourseTable();
    auto it = courseTable.find(selectedCourseId);
    checkprerequisites checker;
    bool prerequisitesCompleted = checker.checkCourseValidation(selectedCourseId);
    if (it != courseTable.end() && prerequisitesCompleted ) {
        const Course &course = it->second;

        QMessageBox::information(this,
                                 "Registration Successful",
                                 "You have registered for:\n" + course.getTitle()
                                     + "\nCredit Hours: "
                                     + QString::number(course.getCreditHours()));
        registerCourse::regCnt++;
        admin->updateRegistrationsCnt(registerCourse::regCnt);

    } else {
        if (prerequisitesCompleted == false) QMessageBox::warning(this, "Error", "You did not complete the prerequisites of this course.");
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

void registerCourse::on_pushButton_clicked()
{
    QString courseName = ui->searchText->text();
    bool found = false;
    unordered_map<int,Course> &courseTable = uploadCourse::getCourseTable();
    int courseId;
    Course courseToBeDisplayed;
    unordered_map<int, Course> searchCourse;
    unordered_map<int, Course>::iterator it = courseTable.begin();
    while(it != courseTable.end()){
        if(it->second.getTitle() == courseName)
        {
            found = true;
            courseId = it->first;
            courseToBeDisplayed = it->second;
            break;
        }
        it++;
    }
    if(!found){
        QMessageBox::warning(this,"No Course Selected", "course not found");
    }else{
        ui->titleItem->clearContents();
        ui->titleItem->setRowCount(1);

        ui->titleItem->setItem(0, 0, new QTableWidgetItem(QString::number(courseId)));
        ui->titleItem->setItem(0, 1, new QTableWidgetItem(courseToBeDisplayed.getTitle()));
        ui->titleItem->setItem(0, 2, new QTableWidgetItem(QString::number(courseToBeDisplayed.getCreditHours())));
        ui->titleItem->setRowHeight(0, 30);
    }



}


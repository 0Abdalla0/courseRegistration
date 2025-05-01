#include "setprerequisites.h"
#include "ui_setprerequisites.h"
#include"adminPage.h"
#include "uploadcourse.h"
#include "course.h"
#include <stack>
#include <QMessageBox>
#include <QTextStream>
#include <vector>
#include<QFile>
setPrerequisites::setPrerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::setPrerequisites)

{

    ui->setupUi(this);
    for (const auto& [id, course] : uploadCourse::getCourseTable()) {
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
    int preID = preTitle.toInt();
    QString courseid =ui->coursescmb->currentText();
    int id =courseid.toInt();
    if(id == preID){
        QMessageBox::warning(this,"wrong input","Prerequisite id can not be course id");
    }else{
        QMessageBox::information(this,"SUCCESS SETTING","Prerequisite is susccessful setted");
        setPrerequisites::getPrerequisitesTable()[id].push_back(preID);
    }

}
map<int, vector<int>>& setPrerequisites::getPrerequisitesTable(){
    static map<int, vector<int>> prerequisitesTable;
    return prerequisitesTable;
}
void setPrerequisites::savePrerequisitesToFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Could not open prerequisites file for writing.";
        return;
    }

    QTextStream out(&file);

    // For each course with prerequisites...
    for (const auto& [courseId, preList] : getPrerequisitesTable()) {
        if (preList.empty())
            continue;  // skip courses with no prerequisites

        // Write the course ID...
        out << courseId;

        // ...then each prereq ID, comma-separated
        for (int i = 0; i < preList.size(); ++i) {
            out << "," << preList[i];
        }

        // End with a separator line (same style as your courses file)
        out << "\n-----------------------------------------------------------------\n";
    }

    file.close();
}
void setPrerequisites::loadPrerequisitesFromFile(const QString& filename)
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

        if (parts.size() == 2) {
            int id = parts[0].toInt();
            int preid = parts[1].toInt();

            // Append to the prerequisites vector
            setPrerequisites::getPrerequisitesTable()[id].push_back(preid);
        }
    }

    file.close();
}

#include <QApplication>
#include "mainwindow.h"
#include "setprerequisites.h"
#include "uploadcourse.h"
#include <iostream>
#include"managegrades.h"
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.loadUsersFromFile();
    uploadCourse courses;
    courses.loadCoursesFromFile("courses.txt");
    setPrerequisites prerequisites;
    manageGrades grades;
    grades.loadFromCsv("students'grades.csv");
    prerequisites.loadPrerequisitesFromFile("prerequisites.txt");
    w.show();
    return a.exec();
}

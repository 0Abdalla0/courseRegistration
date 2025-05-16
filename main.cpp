#include <QApplication>
#include "mainwindow.h"
#include "managegrades.h"
#include "setprerequisites.h"
#include "uploadcourse.h"
#include <iostream>
#include "registercourse.h"
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
    registerCourse reg;
    grades.loadFromCsv("students'grades.csv");
    prerequisites.loadPrerequisitesFromFile("prerequisites.txt");
    reg.loadFromFile("registered.txt");
    w.show();
    return a.exec();
}

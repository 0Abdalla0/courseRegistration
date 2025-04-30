#include <QApplication>
#include "mainwindow.h"
#include"uploadcourse.h"
#include"setprerequisites.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.loadUsersFromFile();
    uploadCourse courses;
    courses.loadCoursesFromFile("courses.txt");
    setPrerequisites prerequisites;
    prerequisites.loadPrerequisitesFromFile("prerequisites.txt");
    w.show();
    return a.exec();
}

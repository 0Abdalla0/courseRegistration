#include <QApplication>
#include "mainwindow.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "okkkkk";

    QApplication a(argc, argv);
    MainWindow w;
    w.loadUsersFromFile();
    w.show();
    return a.exec();
}

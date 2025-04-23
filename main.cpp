#include <QApplication>
#include "mainwindow.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    printf("→ entered main()\n");    // C-style so it appears even if Qt isn’t up
    fflush(stdout);

    QApplication a(argc, argv);
    printf("→ after QApplication()\n");
    fflush(stdout);

    MainWindow w;
    w.loadUsersFromFile();
    w.show();
    return a.exec();
}

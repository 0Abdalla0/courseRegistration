#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1366, 768); // Set your desired width and height

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_registerbtn_windowIconChanged(const QIcon &icon)
{

}


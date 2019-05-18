#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dlgaddplane.h"
#include "dlgfindplanes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    DlgAddPlane dlgAddPlane(this);
    dlgAddPlane.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    DlgFindPlanes dlgFindPlanes(this);
    dlgFindPlanes.exec();
}

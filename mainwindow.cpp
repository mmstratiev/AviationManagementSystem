#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dlgaddplane.h"
#include "dlgfindplanes.h"

#include "datamanager.h"

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

void MainWindow::on_AddPlaneBtn_clicked()
{
    DlgAddPlane dlgAddPlane(this);
    if(dlgAddPlane.exec() == QDialog::Accepted)
    {
        DataManager::GetInstance();
    }
}

void MainWindow::on_FindPlanesBtn_clicked()
{
    DlgFindPlanes dlgFindPlanes(this);
    dlgFindPlanes.exec();
}

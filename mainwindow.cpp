#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>

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
        DataManager::AddPlane(dlgAddPlane.GetPlaneObj());
    }
}

void MainWindow::on_FindPlanesBtn_clicked()
{
    DlgFindPlanes dlgFindPlanes(this);
    dlgFindPlanes.exec();
}


void MainWindow::on_LoadSettingsBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Select settings file"),
                                                    "/home/",
                                                    tr("Text files (*.txt)"));

    if(!fileName.isEmpty())
    {
        DataManager::Load(fileName);
    }
}

void MainWindow::on_SaveSettingsBtn_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home/untitled.txt",
                               tr("Text files (*.txt)"));

    if(!fileName.isEmpty())
    {
        DataManager::Save(fileName);
    }
}

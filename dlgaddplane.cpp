#include "dlgaddplane.h"
#include "ui_dlgaddplane.h"
#include "dlgcreateplaneclass.h"
#include "datamanager.h"

#include <QMessageBox>

DlgAddPlane::DlgAddPlane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAddPlane)
{
    ui->setupUi(this);

    for(auto const &it : DataManager::GetAllPlaneClasses())
    {
        ui->PlaneClassesCombo->addItem(it->getName());
    }
}

DlgAddPlane::~DlgAddPlane()
{
    delete ui;
}

void DlgAddPlane::accept()
{
    if(ui->PlaneIDEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Plane ID cannot be empty!");
        msgBox.exec();
    }
    else if(ui->PlaneClassesCombo->currentText().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Plane class cannot be empty!");
        msgBox.exec();
    }
    else if(DataManager::GetPlane(ui->PlaneIDEdit->text()))
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Message", "A plane with that name already exists! Do you want to overwrite it?");
        if(reply == QMessageBox::Yes)
        {
            QDialog::accept();
        }
    }
    else
    {
        QDialog::accept();
    }
}

QSharedPointer<Plane> DlgAddPlane::GetPlaneObj()
{
    QSharedPointer<Plane> result(new Plane());

    result->setID(ui->PlaneIDEdit->text());
    result->setPlaneType(DataManager::GetPlaneClass(ui->PlaneClassesCombo->currentText()));

    return result;
}

void DlgAddPlane::on_NewClassBtn_clicked()
{
    DlgCreatePlaneClass dlgCreatePlaneClass(this);
    if(dlgCreatePlaneClass.exec() == QDialog::Accepted)
    {
        QSharedPointer<PlaneClass> newPlaneClass = dlgCreatePlaneClass.GetPlaneClassObj();
        DataManager::AddPlaneClass(newPlaneClass);

        if(ui->PlaneClassesCombo->findText(newPlaneClass->getName()) == -1)
        {
            ui->PlaneClassesCombo->insertItem(0, dlgCreatePlaneClass.GetPlaneClassObj()->getName());
            ui->PlaneClassesCombo->setCurrentIndex(0);
        }
    }
}

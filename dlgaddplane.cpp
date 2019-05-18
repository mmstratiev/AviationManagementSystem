#include "dlgaddplane.h"
#include "ui_dlgaddplane.h"
#include "dlgcreateplaneclass.h"

DlgAddPlane::DlgAddPlane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAddPlane)
{
    ui->setupUi(this);
}

DlgAddPlane::~DlgAddPlane()
{
    delete ui;
}

void DlgAddPlane::on_NewClassBtn_clicked()
{
    DlgCreatePlaneClass dlgCreatePlaneClass(this);
    if(dlgCreatePlaneClass.exec() == QDialog::Accepted)
    {
        ui->PlaneClassesCombo->insertItem(0, dlgCreatePlaneClass.GetPlaneClassObj()->getName());
        ui->PlaneClassesCombo->setCurrentIndex(0);
    }
}

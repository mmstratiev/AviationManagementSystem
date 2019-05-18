#include "dlgaddplane.h"
#include "ui_dlgaddplane.h"
#include "dlgcreateplaneclass.h"

DlgAddPlane::DlgAddPlane(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAddPlane)
{
    ui->setupUi(this);
    ui->PlaneClassesCombo->addItem("New class...");
}

DlgAddPlane::~DlgAddPlane()
{
    delete ui;
}

void DlgAddPlane::on_PlaneClassesCombo_currentIndexChanged(int index)
{
    if(index == ui->PlaneClassesCombo->count() - 1)
    {
        DlgCreatePlaneClass dlgCreatePlaneClass(this);
        if(dlgCreatePlaneClass.exec() == QDialog::Accepted)
        {
        }
    }
}

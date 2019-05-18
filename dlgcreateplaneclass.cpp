#include "dlgcreateplaneclass.h"
#include "ui_dlgcreateplaneclass.h"
#include <QMessageBox>

DlgCreatePlaneClass::DlgCreatePlaneClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCreatePlaneClass)
{
    ui->setupUi(this);
}

DlgCreatePlaneClass::~DlgCreatePlaneClass()
{
    delete ui;
}

void DlgCreatePlaneClass::accept()
{
    if(ui->ClassNameEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Class name cannot be empty!");
        msgBox.exec();
    }
    else
    {
        QDialog::accept();
    }
}

QSharedPointer<PlaneClass> DlgCreatePlaneClass::GetPlaneClassObj()
{
    QSharedPointer<PlaneClass> result(new PlaneClass());

    result->setName(ui->ClassNameEdit->text());
    result->setMaker(ui->MakerEdit->text());
    result->setMaker(ui->ModelEdit->text());
    result->setSeatCount(ui->SeatsSpinBox->value());
    result->setTrackLength(ui->TrackLengthSpinBox->value());

    return result;
}

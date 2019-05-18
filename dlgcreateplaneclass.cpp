#include "dlgcreateplaneclass.h"
#include "ui_dlgcreateplaneclass.h"

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

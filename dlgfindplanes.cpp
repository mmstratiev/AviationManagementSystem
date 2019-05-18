#include "dlgfindplanes.h"
#include "ui_dlgfindplanes.h"

DlgFindPlanes::DlgFindPlanes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgFindPlanes)
{
    ui->setupUi(this);
}

DlgFindPlanes::~DlgFindPlanes()
{
    delete ui;
}

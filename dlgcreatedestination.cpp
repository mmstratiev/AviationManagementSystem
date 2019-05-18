#include "dlgcreatedestination.h"
#include "ui_dlgcreatedestination.h"

#include <QMessageBox>

#include "datamanager.h"

DlgCreateDestination::DlgCreateDestination(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCreateDestination)
{
    ui->setupUi(this);
}

DlgCreateDestination::~DlgCreateDestination()
{
    delete ui;
}

void DlgCreateDestination::accept()
{
    if(ui->DestinationNameEdit->text().isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("Destination name cannot be empty!");
        msgBox.exec();
    }
    else if(DataManager::GetDestination(ui->DestinationNameEdit->text()))
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Message", "A destination with that name already exists! Do you want to overwrite it?");
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

QSharedPointer<Destination> DlgCreateDestination::GetDestinationObj()
{
    QSharedPointer<Destination> result(new Destination());

    result->setName(ui->DestinationNameEdit->text());
    result->setDistance(ui->DistanceSpinBox->value());

    return result;
}

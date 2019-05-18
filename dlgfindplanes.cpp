#include "dlgfindplanes.h"
#include "ui_dlgfindplanes.h"
#include "dlgcreatedestination.h"

#include "destination.h"
#include "datamanager.h"

DlgFindPlanes::DlgFindPlanes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgFindPlanes)
{
    ui->setupUi(this);

    for(auto const &it : DataManager::GetAllDestinations())
    {
        ui->DestinationsComboBox->addItem(it->getName());
    }
}

DlgFindPlanes::~DlgFindPlanes()
{
    delete ui;
}

void DlgFindPlanes::on_NewDestinationBtn_clicked()
{
    DlgCreateDestination dlgCreateDestination(this);

    if(dlgCreateDestination.exec() == QDialog::Accepted)
    {
        QSharedPointer<Destination> newDestination = dlgCreateDestination.GetDestinationObj();
        DataManager::AddDestination(newDestination);

        if(ui->DestinationsComboBox->findText(newDestination->getName()) == -1)
        {
            ui->DestinationsComboBox->insertItem(0, newDestination->getName());
            ui->DestinationsComboBox->setCurrentIndex(0);
        }
    }
}

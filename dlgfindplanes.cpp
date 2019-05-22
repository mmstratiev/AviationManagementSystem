#include "dlgfindplanes.h"
#include "ui_dlgfindplanes.h"
#include "dlgcreatedestination.h"

#include "destination.h"
#include "datamanager.h"
#include "plane.h"
#include "planeclass.h"

DlgFindPlanes::DlgFindPlanes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgFindPlanes)
{
    ui->setupUi(this);

    for(auto const &it : DataManager::GetAllDestinations())
    {
        ui->DestinationsComboBox->addItem(it->getName());
    }

    QStringList horizontalHeader;
    horizontalHeader.append("Plane ID");
    horizontalHeader.append("Plane Class");

//    ui->PlanesTable->setColumnCount(2);

//    ui->PlanesTable->setHorizontalHeaderLabels(horizontalHeader);

//    ui->PlanesTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Plane ID"));
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

void DlgFindPlanes::on_DestinationsComboBox_currentIndexChanged(const QString &arg1)
{
    QSharedPointer<const Destination> destination = DataManager::GetDestination(arg1);
    QVector<QSharedPointer<const Plane>> planes = DataManager::GetAllPlanes();

    ui->planesList->clear();

    for(QSharedPointer<const Plane> plane : planes)
    {
        if(plane->getPlaneType()->CanReachDestination(destination))
        {
            QString itemText = "Plane ID: " + plane->getID() + "; Plane Class: " + plane->getPlaneType()->getName();
            ui->planesList->insertItem(ui->planesList->count()-1, new QListWidgetItem(itemText));
        }
    }
}

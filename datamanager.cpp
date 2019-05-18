#include "datamanager.h"

#include <QMap>
#include <QVector>
#include <QSharedPointer>

QMap<QString, QSharedPointer<Plane>> DataManager::Planes;
QMap<QString, QSharedPointer<PlaneClass>> DataManager::PlaneClasses;
QMap<QString, QSharedPointer<Destination>> DataManager::Destinations;

DataManager::DataManager()
{

}

DataManager &DataManager::GetInstance()
{
    static DataManager instance;

    return instance;
}

void DataManager::AddPlane(QSharedPointer<Plane> plane)
{
    Planes.insert(plane->getID(), plane);
}

void DataManager::AddPlaneClass(QSharedPointer<PlaneClass> planeClass)
{
    PlaneClasses.insert(planeClass->getName(), planeClass);
}

void DataManager::AddDestination(QSharedPointer<Destination> destination)
{
    Destinations.insert(destination->getName(), destination);
}

QSharedPointer<const Plane> DataManager::GetPlane(QString name)
{
    QSharedPointer<const Plane> result;

    auto const it = Planes.constFind(name);

    if(it != Planes.constEnd())
    {
        result = *it;
    }

    return result;
}

QSharedPointer<const PlaneClass> DataManager::GetPlaneClass(QString name)
{
    QSharedPointer<const PlaneClass> result;

    auto const it = PlaneClasses.constFind(name);

    if(it != PlaneClasses.constEnd())
    {
        result = *it;
    }

    return result;
}

QSharedPointer<const Destination> DataManager::GetDestination(QString name)
{
    QSharedPointer<const Destination> result;

    auto const it = Destinations.constFind(name);

    if(it != Destinations.constEnd())
    {
        result = *it;
    }

    return result;
}

QVector<QSharedPointer<const Plane>> DataManager::GetAllPlanes()
{
    QVector<QSharedPointer<const Plane>> result;

    for(QSharedPointer<const Plane> it : Planes)
    {
        result.push_back(it);
    }

    return result;
}

QVector<QSharedPointer<const PlaneClass> > DataManager::GetAllPlaneClasses()
{
    QVector<QSharedPointer<const PlaneClass>> result;

    for(QSharedPointer<const PlaneClass> it : PlaneClasses)
    {
        result.push_back(it);
    }

    return result;
}

QVector<QSharedPointer<const Destination> > DataManager::GetAllDestinations()
{
    QVector<QSharedPointer<const Destination>> result;

    for(QSharedPointer<const Destination> it : Destinations)
    {
        result.push_back(it);
    }

    return result;
}

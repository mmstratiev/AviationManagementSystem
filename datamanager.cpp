#include "datamanager.h"

#include <QFile>
#include <QMap>
#include <QVector>
#include <QSharedPointer>
#include <QDebug>

#include "plane.h"

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

void DataManager::Save(QString filePath)
{
    QFile saveFile(filePath);
    if(saveFile.open(QIODevice::WriteOnly))
    {
        QDataStream out(&saveFile);

        out << PlaneClasses.count();
        for(auto const &it : PlaneClasses)
        {
            out << *it;
        }

        out << Planes.count();
        for(auto const &it : Planes)
        {
            out << *it;
        }

        out << Destinations.count();
        for(auto const &it : Destinations)
        {
            out << *it;
        }
    }

    saveFile.close();
}

void DataManager::Load(QString filePath)
{
    QFile saveFile(filePath);
    if(saveFile.open(QIODevice::ReadOnly))
    {
        QDataStream in(&saveFile);

        int planeClassCount = 0;
        in >> planeClassCount;
        for(int i = 0; i < planeClassCount; i++)
        {
            QSharedPointer<PlaneClass> planeClass(new PlaneClass());
            in >> *planeClass;
            DataManager::AddPlaneClass(planeClass);
        }

        int planeCount = 0;
        in >> planeCount;
        for(int i = 0; i < planeCount; i++)
        {
            QSharedPointer<Plane> plane(new Plane());
            in >> *plane;
            DataManager::AddPlane(plane);
        }

        int destinationCount = 0;
        in >> destinationCount;
        for(int i = 0; i < destinationCount; i++)
        {
            QSharedPointer<Destination> destination(new Destination());
            in >> *destination;
            DataManager::AddDestination(destination);
        }
    }

    saveFile.close();
}

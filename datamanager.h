#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "plane.h"
#include "planeclass.h"
#include "destination.h"

class DataManager
{
public:
    DataManager(DataManager const&)     = delete;
    void operator=(DataManager const&)  = delete;

    static DataManager& GetInstance();

    static void AddPlane(QSharedPointer<Plane> plane);
    static void AddPlaneClass(QSharedPointer<PlaneClass> planeClass);
    static void AddDestination(QSharedPointer<Destination> destination);

    static QSharedPointer<const Plane> GetPlane(QString name);
    static QSharedPointer<const PlaneClass> GetPlaneClass(QString name);
    static QSharedPointer<const Destination> GetDestination(QString name);

    static QVector<QSharedPointer<const Plane>> GetAllPlanes();
    static QVector<QSharedPointer<const PlaneClass>> GetAllPlaneClasses();
    static QVector<QSharedPointer<const Destination>> GetAllDestinations();

private:
    DataManager();

    static QMap<QString, QSharedPointer<Plane>> Planes;
    static QMap<QString, QSharedPointer<PlaneClass>> PlaneClasses;
    static QMap<QString, QSharedPointer<Destination>> Destinations;
};

#endif // DATAMANAGER_H

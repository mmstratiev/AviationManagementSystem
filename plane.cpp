#include "plane.h"

Plane::Plane()
{

}

QString Plane::getID() const
{
    return ID;
}

void Plane::setID(const QString &value)
{
    ID = value;
}

QSharedPointer<const PlaneClass> Plane::getPlaneType() const
{
    return PlaneType;
}

void Plane::setPlaneType(const QSharedPointer<const PlaneClass> &value)
{
    PlaneType = value;
}

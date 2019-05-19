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

//QDataStream &operator>>(QDataStream &in, Plane &p)
//{
//    QString className;
//    p = Plane();

//    in >> p.ID >> className;

//    p.PlaneType = DataManager::GetPlaneClass(className);

//    return in;
//}

#ifndef PLANE_H
#define PLANE_H

#include <QString>
#include <QSharedPointer>
#include "planeclass.h"
#include "datamanager.h"

class Plane
{
public:
    Plane();

    QString getID() const;
    void setID(const QString &value);

    QSharedPointer<const PlaneClass> getPlaneType() const;
    void setPlaneType(const QSharedPointer<const PlaneClass> &value);

    // ostream, << overloading
    friend QDataStream &operator<<(QDataStream &out, const Plane &p)
    {
        out << p.ID << p.PlaneType->getName();
        return out;
    }

    // istream, >> overloading
    friend QDataStream &operator>>(QDataStream &in, Plane &p)
    {
        QString className;
        p = Plane();

        in >> p.ID >> className;
        p.PlaneType = DataManager::GetPlaneClass(className);

        return in;
    }

private:
    QString     ID;
    QSharedPointer<const PlaneClass> PlaneType;
};

//QDataStream &operator>>(QDataStream &in, Plane &p);

#endif // PLANE_H

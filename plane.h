#ifndef PLANE_H
#define PLANE_H

#include <QString>
#include <QSharedPointer>
#include "planeclass.h"

class Plane
{
public:
    Plane();

    QString getID() const;
    void setID(const QString &value);

    QSharedPointer<const PlaneClass> getPlaneType() const;
    void setPlaneType(const QSharedPointer<const PlaneClass> &value);

private:
    QString     ID;
    QSharedPointer<const PlaneClass> PlaneType;
};

#endif // PLANE_H

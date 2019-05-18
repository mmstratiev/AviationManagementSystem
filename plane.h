#ifndef PLANE_H
#define PLANE_H

#include <QString>
#include "planeclass.h"

class Plane
{
public:
    Plane();

private:
    QString     ID;
    PlaneClass  PlaneType;
};

#endif // PLANE_H

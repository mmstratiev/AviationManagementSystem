#ifndef PLANECLASS_H
#define PLANECLASS_H

#include <QString>

class PlaneClass
{
public:
    PlaneClass();

private:
    QString Maker;
    QString Model;
    qint32  SeatCount;
    qint16  TrackLenght;
};

#endif // PLANECLASS_H

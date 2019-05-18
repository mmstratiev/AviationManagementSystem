#include "planeclass.h"

PlaneClass::PlaneClass()
{

}

QString PlaneClass::getMaker() const
{
    return Maker;
}

void PlaneClass::setMaker(const QString &value)
{
    Maker = value;
}

QString PlaneClass::getModel() const
{
    return Model;
}

void PlaneClass::setModel(const QString &value)
{
    Model = value;
}

qint32 PlaneClass::getSeatCount() const
{
    return SeatCount;
}

void PlaneClass::setSeatCount(const qint32 &value)
{
    SeatCount = value;
}

qint32 PlaneClass::getTrackLenght() const
{
    return TrackLength;
}

void PlaneClass::setTrackLength(const qint32 &value)
{
    TrackLength = value;
}

QString PlaneClass::getName() const
{
    return Name;
}

void PlaneClass::setName(const QString &value)
{
    Name = value;
}

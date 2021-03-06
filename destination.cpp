#include "destination.h"

Destination::Destination()
{

}

QString Destination::getName() const
{
    return Name;
}

void Destination::setName(const QString &value)
{
    Name = value;
}

qint32 Destination::getDistance() const
{
    return Distance;
}

void Destination::setDistance(const qint32 &value)
{
    Distance = value;
}

qint32 Destination::getTrackLength() const
{
    return TrackLength;
}

void Destination::setTrackLength(const qint32 &value)
{
    TrackLength = value;
}


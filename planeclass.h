#ifndef PLANECLASS_H
#define PLANECLASS_H

#include <QString>
#include <QDataStream>

class Destination;

class PlaneClass
{
public:
    PlaneClass();

    QString getMaker() const;
    void setMaker(const QString &value);

    QString getModel() const;
    void setModel(const QString &value);

    qint32 getSeatCount() const;
    void setSeatCount(const qint32 &value);

    qint32 getTrackLenght() const;
    void setTrackLength(const qint32 &value);

    QString getName() const;
    void setName(const QString &value);

    qreal getFuelConsumption() const;
    void setFuelConsumption(const qreal &value);

    qreal getFuelCapacity() const;
    void setFuelCapacity(const qreal &value);

    bool CanReachDestination(QSharedPointer<const Destination> destination) const;

    // ostream, << overloading
    friend QDataStream &operator<<(QDataStream &out, const PlaneClass &p)
    {
        out << p.Name << p.Maker << p.Model << p.SeatCount << p.TrackLength << p.FuelConsumption << p.FuelCapacity;
        return out;
    }

    // istream, >> overloading
    friend QDataStream &operator>>(QDataStream &in, PlaneClass &p)
    {
        p = PlaneClass();
        in >> p.Name >> p.Maker >> p.Model >> p.SeatCount >> p.TrackLength >> p.FuelConsumption >> p.FuelCapacity;
        return in;
    }

private:
    QString Name;
    QString Maker;
    QString Model;
    qint32  SeatCount;
    qint32  TrackLength;
    qreal   FuelConsumption;
    qreal   FuelCapacity;
};

#endif // PLANECLASS_H

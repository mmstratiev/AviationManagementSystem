#ifndef PLANECLASS_H
#define PLANECLASS_H

#include <QString>
#include <QDataStream>

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

    // ostream, << overloading
    friend QDataStream &operator<<(QDataStream &out, const PlaneClass &p)
    {
        out << p.Name << p.Maker << p.Model << p.SeatCount << p.TrackLength;
        return out;
    }

    // istream, >> overloading
    friend QDataStream &operator>>(QDataStream &in, PlaneClass &p)
    {
        p = PlaneClass();
        in >> p.Name >> p.Maker >> p.Model >> p.SeatCount >> p.TrackLength;
        return in;
    }

private:
    QString Name;
    QString Maker;
    QString Model;
    qint32  SeatCount;
    qint32  TrackLength;
};

#endif // PLANECLASS_H

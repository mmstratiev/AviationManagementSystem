#ifndef DESTINATION_H
#define DESTINATION_H

#include <QString>
#include <QDataStream>

class Destination
{
public:
    Destination();

    QString getName() const;
    void setName(const QString &value);

    qint32 getDistance() const;
    void setDistance(const qint32 &value);

    qint32 getTrackLength() const;
    void setTrackLength(const qint32 &value);

    // ostream, << overloading
    friend QDataStream &operator<<(QDataStream &out, const Destination &d)
    {
        out << d.Name << d.Distance << d.TrackLength;
        return out;
    }

    // istream, >> overloading
    friend QDataStream &operator>>(QDataStream &in, Destination &d)
    {
        d = Destination();
        in >> d.Name >> d.Distance >> d.TrackLength;
        return in;
    }

private:
    QString Name;
    qint32  TrackLength;
    qint32  Distance;
};

#endif // DESTINATION_H

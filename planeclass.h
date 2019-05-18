#ifndef PLANECLASS_H
#define PLANECLASS_H

#include <QString>

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

private:
    QString Name;
    QString Maker;
    QString Model;
    qint32  SeatCount;
    qint32  TrackLength;
};

#endif // PLANECLASS_H

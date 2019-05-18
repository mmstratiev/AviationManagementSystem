#ifndef DESTINATION_H
#define DESTINATION_H

#include <QString>

class Destination
{
public:
    Destination();

    QString getName() const;
    void setName(const QString &value);

    qint32 getDistance() const;
    void setDistance(const qint32 &value);

private:
    QString Name;
    qint32  Distance;
};

#endif // DESTINATION_H

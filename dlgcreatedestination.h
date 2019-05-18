#ifndef DLGCREATEDESTINATION_H
#define DLGCREATEDESTINATION_H

#include <QDialog>

#include "destination.h"

namespace Ui {
class DlgCreateDestination;
}

class DlgCreateDestination : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCreateDestination(QWidget *parent = nullptr);
    ~DlgCreateDestination();

    virtual void accept() override;

    QSharedPointer<Destination> GetDestinationObj();
private:
    Ui::DlgCreateDestination *ui;
};

#endif // DLGCREATEDESTINATION_H

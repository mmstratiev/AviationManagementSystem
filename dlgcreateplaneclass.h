#ifndef DLGCREATEPLANECLASS_H
#define DLGCREATEPLANECLASS_H

#include <QDialog>
#include "planeclass.h"

namespace Ui {
class DlgCreatePlaneClass;
}

class DlgCreatePlaneClass : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCreatePlaneClass(QWidget *parent = nullptr);
    ~DlgCreatePlaneClass();

    virtual void accept() override;

    QSharedPointer<PlaneClass> GetPlaneClassObj();

private:
    Ui::DlgCreatePlaneClass *ui;
};

#endif // DLGCREATEPLANECLASS_H

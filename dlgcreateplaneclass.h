#ifndef DLGCREATEPLANECLASS_H
#define DLGCREATEPLANECLASS_H

#include <QDialog>

namespace Ui {
class DlgCreatePlaneClass;
}

class DlgCreatePlaneClass : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCreatePlaneClass(QWidget *parent = nullptr);
    ~DlgCreatePlaneClass();

private:
    Ui::DlgCreatePlaneClass *ui;
};

#endif // DLGCREATEPLANECLASS_H

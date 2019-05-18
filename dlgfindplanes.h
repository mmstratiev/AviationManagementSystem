#ifndef DLGFINDPLANES_H
#define DLGFINDPLANES_H

#include <QDialog>

namespace Ui {
class DlgFindPlanes;
}

class DlgFindPlanes : public QDialog
{
    Q_OBJECT

public:
    explicit DlgFindPlanes(QWidget *parent = nullptr);
    ~DlgFindPlanes();

private:
    Ui::DlgFindPlanes *ui;
};

#endif // DLGFINDPLANES_H

#ifndef DLGADDPLANE_H
#define DLGADDPLANE_H

#include <QDialog>

namespace Ui {
class DlgAddPlane;
}

class DlgAddPlane : public QDialog
{
    Q_OBJECT

public:
    explicit DlgAddPlane(QWidget *parent = nullptr);
    ~DlgAddPlane();

private slots:
    void on_NewClassBtn_clicked();

private:
    Ui::DlgAddPlane *ui;
};

#endif // DLGADDPLANE_H

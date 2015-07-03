#ifndef OWNER_H
#define OWNER_H

#include <QDialog>
#include "gestionaralumno.h"
//#include "gestionarreuniones.h">
#include "maincontroller.h"


namespace Ui {
class gestor;
}

class gestor : public QDialog
{
    Q_OBJECT

public:
    explicit gestor(QWidget *parent = 0);
    ~gestor();

    void setControllers (MainController &);

private:
    Ui::gestor *ui;

    MainController *controller_;

private slots:
    void openVentana31();
    //void openVentana2();
    //void openVentana3();
};

#endif // OWNER_H

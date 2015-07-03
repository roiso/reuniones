#ifndef GESTIONARALUMNO_H
#define GESTIONARALUMNO_H

#include <QDialog>
#include "maincontroller.h"
#include <qmessagebox.h>
#include "util.h"
#include "gestor.h"
#include <QMessageBox>
#include <QDebug>



namespace Ui {

class gestionarAlumno;
}

class gestionarAlumno : public QDialog
{
    Q_OBJECT

public:
    explicit gestionarAlumno(QWidget *parent = 0);
    ~gestionarAlumno();

    void setController (MainController &);

private:
    Ui::gestionarAlumno *ui;

    MainController *controller_;
    pel::List<int> buscarAlumno;

    c_alumno criterio;
    //int mostrados;
    int opcion;

    void inicial();
    void limpiarLabel();

private slots:
    void showAlumno();
    void showLabel();
    void nuevo();
    void modificar();
    void borrar();
    void aceptar();
    void cancelar();

};
#endif // GESTIONARALUMNO_H

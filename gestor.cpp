#include "gestor.h"
#include "ui_gestor.h"



gestor::gestor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestor)
{
    ui->setupUi(this);
}

gestor::~gestor()
{

}


void gestor::openVentana31(){
    gestionarAlumno v1;
    v1.setController(*controller_);
    v1.exec();
}
/*
void gestor::openVentana32(){
    gestionarReuniones v2;
    v2.setController(*controller_);
    v2.exec();
}

void gestor::openVentana33(){
    consultarReuniones v3;
    v3.setController(*controller_);
    v3.exec();
}
*/
void gestor::setControllers (MainController &controller){
    controller_=&controller;
}


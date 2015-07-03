#include "maincontroller.h"
#include <QDebug>
#include <algorithm>
#include <qmessagebox.h>


MainController::MainController() {

}

void MainController::init(){
    load_alumnos();
    //load_reuniones();

}

MainController::~MainController() {

}


int MainController::getUltimoIDalumno() const
{
    return ultimoIDalumno;
}

void MainController::setUltimoIDalumno()
{
    ultimoIDalumno++;
}

void MainController::load_alumnos() {
    alumnos=CargaDatos::leerAlumno();
}
/*
void MainController::load_reuniones() {
    reuniones=CargaDatos::leerReunion();
}
*/
pel::List<c_alumno> MainController::getAlumnos(){
    return alumnos;
}
/*
pel::List<c_reuniones> MainController::getreuniones(){
    return reuniones;
}

*/


void MainController::setAlumnos(c_alumno setAlumnos){
    alumnos.append(setAlumnos);
}


/*
void MainController::setReuniones(c_reuniones setReunion){
    reuniones.append(setReunion);
}
*/
void MainController::modificarAlumnos(int posicion, c_alumno modificado){
    auto iter = alumnos.begin();
    for (int i=0; i<posicion; i++){
        iter++;
    }
    alumnos.replace(iter, modificado);
}
/*
void MainController::modificarReuniones(int posicion, c_reuniones modificado){
    auto iter = reuniones.begin();
    for (int i=0; i<posicion; i++){
        iter++;
    }
    reuniones.replace(iter, modificado);

}
*/
void MainController::limpiarListas(int *alumno){//, int *reunion){


    pel::List<size_t>borraralumnos;
    auto iter3 = alumnos.begin();
    size_t count3 = alumnos.count();
    for (size_t i=0; i<count3; i++){
        if (alumnos.at(i).borrado()==true){
            borraralumnos.append(i);
        }
        ++iter3;
    }

    for (size_t i=borraralumnos.count(); i>0; i--){
        auto iter33 = alumnos.end();
        qDebug()<<borraralumnos.at(i-1);
        size_t count33 = borraralumnos.at(i-1);
        for (size_t j=alumnos.count(); j>count33; j--){
            --iter33;
        }
        alumnos.erase(iter33);
    }
/*
    pel::List<size_t>borrareunion;
    auto iter4 = reuniones.begin();
    size_t count4 = reuniones.count();
    for (size_t i=0; i<count4; i++){
        if (reuniones.at(i).borrado()==true){
            borrareunion.append(i);
        }
        ++iter4;
    }

    for (size_t i=borrareunion.count(); i>0; i--){
        auto iter44 = reuniones.end();
        qDebug()<<borrareunion.at(i-1);
        size_t count44 = borrareunion.at(i-1);
        for (size_t j=reuniones.count(); j>count44; j--){
            --iter44;
        }
       reuniones.erase(iter44);
    }

*/
    *alumno = borraralumnos.count();
    //*reunion = borrareunion.count();

}


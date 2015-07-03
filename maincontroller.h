#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H


//#include "c_reuniones.h"
#include "c_alumno.h"
#include "util.h"
#include "cargadatos.h"
#include "lista.h"


class MainController {
private:

    pel::List <c_alumno> alumnos;
    int ultimoIDalumno=3;
    //pel::List <c_reuniones> reuniones;
    //int ultimoIDreunion=6;





    void load_alumnos ();
    //void load_reuniones ();


public:
    MainController();
    ~MainController();

    void init();


    pel::List<c_alumno> getAlumnos();
    //pel::List<c_reuniones> getreuniones();
    void setAlumnos(c_alumno);
    //void setReuniones(c_reuniones);
    void modificarAlumnos (int, c_alumno);
    //void modificarReuniones (int, c_reuniones);




    void limpiarListas(int *alumnos);//, int *reuniones);
    int getUltimoIDalumno() const;
    void setUltimoIDalumno();
    //int getUltimoIDreuniones() const;
    //void setUltimoIDreuniones();

};

#endif // MAINCONTROLLER_H

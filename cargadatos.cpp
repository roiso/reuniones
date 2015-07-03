#include "cargadatos.h"


CargaDatos::CargaDatos() {

}

CargaDatos::~CargaDatos() {

}


pel::List<c_alumno> CargaDatos::leerAlumno(){
    pel::List<c_alumno> alumnos;

    c_alumno alumno1 (0,"902224411","Pepe","rrr");
    c_alumno alumno2 (1,"912182128","RS","rrr");
    c_alumno alumno3 (2,"19009","pep","llaa");
    
    alumnos.append(alumno1);
    alumnos.append(alumno2);
    alumnos.append(alumno3);

    return alumnos;
}

//pel::List<c_reuniones> CargaDatos::leerReunion(){
    //pel::List<c_reuniones> reuniones;

    //c_reuniones reunion1 (1, 1, "Pepe insulto a juan");
    //c_reuniones reunion2 (2, 1, "Juan se puso a cantar");

    //halcon1.setBorrado(1);
    //reuniones.append(reunion1);
    //reuniones.append(reunion2);


    //return reuniones;
//}






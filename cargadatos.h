#ifndef CARGADATOS_H
#define CARGADATOS_H


#include <c_alumno.h>
#include <c_reuniones.h>
#include <lista.h>

class CargaDatos
{
public:
    CargaDatos();
    ~CargaDatos();

   static pel::List<c_alumno> leerAlumno();
   //static pel::List<c_reuniones> leerReunion();
};

#endif // CARGADATOS_H

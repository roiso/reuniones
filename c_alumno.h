#ifndef C_ALUMNO_H
#define C_ALUMNO_H

#include <string>
#include <QDateTime>
#include <interfaz.h>
//#include "fecha.h"

class c_alumno:public NodoAlumnos{
private:
    int ID_;
    bool borrado_;
    std::string telefono_;
    std::string nombre_;
    std::string email_;

    //Fecha fechaOrdinaria_;
    //Fecha fechaExtraordinaria_;
 

public:
    c_alumno();
    c_alumno(int ID, std::string telefono,std::string nombre,std::string email);//Fecha fechaOrdinaria_,Fecha fechaExtraordinaria_);
    ~c_alumno();

    int ID() const;
    void setID(int ID);
    std::string telefono() const;
    void setTelefono(const std::string &telefono);
    bool borrado() const;
    void setBorrado(bool borrado);
    std::string nombre() const;
    void setNombre(const std::string &nombre);
    std::string email() const;
    void SetEmail(const std::string &email);
    //Fecha fechaOrdinaria() const;
    //void setFechaOrdinaria(Fecha fechaOrdinaria_);
    //Fecha fechaExtraordinaria() const;
    //void SetFechaExtraordinaria(Fecha fechaExtraordinaria_);

    void rellenarFila(QTableWidget *tabla, int pos);
    void setHeader (QTableWidget *tabla);
    bool compare (NodoAlumnos *criterio);
    bool buscarID (int &ID);
    
};

#endif // C_ALUMNO_H

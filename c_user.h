#ifndef C_USER_H
#define C_USER_H

#include <string>
#include <iostream>
#include "interfaz.h"

#include <string>
#include <QDateTime>
#include <interfaz.h>

class c_users: public NodoReuniones{
private:
    int ID_;
    int ID_alumno_;
    int ID_reunion_;
    short role_;
    bool borrado_;
    std::string nombre_;
    std::string usuario_;
    std::string contrasena_;

public:
    c_users();
    c_users(int ID, int ID_alumno, int ID_reunion, short role, std::string nombre, std::string usuario, std::string contrasena);
    ~c_users();

    int ID() const;
    void setID(int ID);
    int ID_alumno() const;
    void setID_alumno(int ID_alumno);
    int ID_reunion() const;
    void setID_reunion(int ID_reunion);
    short role() const;
    void setRole(short role);
    bool borrado() const;
    void setBorrado (bool borrado);
    std::string nombre() const;
    void setNombre(const std::string &nombre);
    std::string usuario() const;
    void setUsuario(const std::string &usuario);
    std::string contrasena() const;
    void setContrasena(const std::string &contrasena);

    void rellenarFila(QTableWidget *tabla, int pos);
    void setHeader (QTableWidget *tabla);
    bool compare (NodoReuniones *criterio);
    bool buscarID (int &ID);
};
#endif // C_USER_H

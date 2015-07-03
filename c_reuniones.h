/*
#ifndef C_REUNION
#define C_REUNION

#include <string>
#include <QDateTime>
#include <interfaz.h>

class c_reuniones:public NodoAlumnos{

private:
    int ID_;
    int ID_alumno_;
    bool borrado_;
    std::string resumen_;
    QDateTime fecha_;

public:
    c_reuniones();
    c_reuniones(int ID, int ID_alumno,std::string resumen);//QDateTime fecha);
    ~c_reuniones();


    int ID() const;
    void setID(int ID);
    bool borrado() const;
    int ID_alumnos() const;
    void setID_alumnos(int ID_alumnos);
    void setBorrado(bool borrado);
    std::string resumen() const;
    void SetResumen(const std::string &resumen);
    //QDateTime fecha() const;
   // void setFecha(const QDate &fecha);
    void rellenarFila(QTableWidget *tabla, int pos);
    void setHeader (QTableWidget *tabla);
    bool compare (NodoAlumnos *criterio);
    bool buscarID (int &ID);
};
#endif // C_REUNION

*/

#include "c_alumno.h"


int c_alumno::ID() const
{
    return ID_;
}

void c_alumno::setID(int ID)
{
    ID_ = ID;
}


std::string c_alumno::telefono() const
{
    return telefono_;
}

void c_alumno::setTelefono(const std::string &telefono)
{
    telefono_ = telefono;
}


bool c_alumno::borrado() const
{
    return borrado_;
}

void c_alumno::setBorrado(bool borrado)
{
    borrado_ = borrado;
}


std::string c_alumno::nombre() const
{
    return nombre_;
}

void c_alumno::setNombre(const std::string &nombre)
{
    nombre_ = nombre;
}

std::string c_alumno::email() const
{
    return email_;
}

void c_alumno::SetEmail(const std::string &email)
{
    email_ = email;
}

/*
Fecha c_alumno::fechaOrdinaria() const
{
    return fechaOrdinaria_;
}

void c_alumno::setFechaOrdinaria(Fecha fechaordinaria)
{
    fechaOrdinaria_=fechaordinaria;
}
Fecha c_alumno::fechaExtraordinaria() const
{
    return fechaExtraordinaria_;
}

void c_alumno::setFechaExtraordinaria(Fecha fechaextraordinaria)
{
    fechaExtraordinaria_=fechaextraordinaria;
}
*/

void c_alumno::rellenarFila(QTableWidget *tabla, int pos){
    //Fecha fechaOrdinaria=fechaOrdinaria_;
    //Fecha fechaExtraordinaria=fechaExtraordinaria_;
    //QString dateO=fechaOrdinaria.toString("dd/MM/yyyy");
    //QString dateE=fechaExtraordinaria.toString("dd/MM/yyyy");


    tabla->setItem(pos,0,new QTableWidgetItem(QString::fromStdString(telefono())));
    tabla->setItem(pos,1,new QTableWidgetItem(QString::fromStdString(nombre())));
    //tabla->setItem(pos,1,new QTableWidgetItem(QDate::getDate(1991,1,12));
    //tabla->setItem(pos,2,new QTableWidgetItem(fechaExtraordinaria));
    tabla->setItem(pos,2,new QTableWidgetItem(QString::fromStdString(email())));
    tabla->setItem(pos,3,new QTableWidgetItem(QString::number(ID())));

}

c_alumno::c_alumno(){ }

c_alumno::c_alumno(int ID,std::string telefono,std::string nombre,
               std::string email):
                   //Fecha fechaOrdinaria,Fecha fechaExtraordinaria) :
               ID_(ID),borrado_(false),telefono_(telefono),
               nombre_(nombre),email_(email){

    //,fechaOrdinaria_(fechaOrdinaria),
               //fechaExtraordinaria_(fechaExtraordinaria)


}

c_alumno::~c_alumno()
{

}

void c_alumno::setHeader(QTableWidget *tabla){
    tabla->setColumnCount(4);
    tabla->hideColumn(3);
    tabla->setHorizontalHeaderLabels(QString("Telefono;Nombre;Email").split(";"));
}

bool c_alumno::compare(NodoAlumnos *criterio){
    bool mostrar=true;
    c_alumno* comparar=static_cast<c_alumno*>(criterio);

    comparar->setBorrado(true);
       if(this->borrado_==comparar->borrado()){
           mostrar=false;
       }


    return mostrar;
}

bool c_alumno::buscarID(int &ID){
    bool encontrado=false;
    if(this->ID()==ID){
        encontrado=true;
    }
    return encontrado;
}




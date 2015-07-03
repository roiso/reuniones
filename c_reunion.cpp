/*
#include "c_reuniones.h"


int c_reuniones::ID() const
{
    return ID_;
}

void c_reuniones::setID(int ID)
{
    ID_ = ID;
}




bool c_reuniones::borrado() const
{
    return borrado_;
}

void c_reuniones::setBorrado(bool borrado)
{
    borrado_ = borrado;
}


std::string c_reuniones::resumen() const
{
    return resumen_;
}

void c_reuniones::SetResumen(const std::string &resumen)
{
    resumen_ = resumen;
}

/*
QDateTime c_reuniones::fecha() const
{
    return fecha_;
}

void c_reuniones::setFecha(const QDate &fecha)
{
    QDateTime nuevo;
    nuevo.setDate(fecha);
    fecha_ = nuevo;
}

void c_reuniones::rellenarFila(QTableWidget *tabla, int pos){
    QDate fecha=fecha_.date();
    QString date=fecha.toString("dd/MM/yyyy");

    tabla->setItem(pos,0,new QTableWidgetItem(QString::fromStdString(resumen())));
    tabla->setItem(pos,1,new QTableWidgetItem(QString(date)));
    tabla->setItem(pos,2,new QTableWidgetItem(QString::number(ID())));


}

void c_reuniones::setHeader(QTableWidget *tabla){
    tabla->setColumnCount(3);
    tabla->hideColumn(2);
    tabla->setHorizontalHeaderLabels(QString("Resumen;Fecha").split(";"));
}

bool c_reuniones::compare(NodoAlumnos *criterio){
    bool mostrar=true;
    c_reuniones* comparar=static_cast<c_reuniones*>(criterio);

    //QDateTime fechaNula;
    //QDate date;
    //date.setDate(1900,01,01);
    //fechaNula.setDate(date);

    if (comparar->ID_!=-1){
        if (borrado_==true){
            mostrar=false;
        }
        if(ID_!=comparar->ID()){
            mostrar=false;
        }
        //if (comparar->fecha().date()!=fechaNula.date() && fecha_.date()!=comparar->fecha().date()){
            mostrar=false;
        }

    }else{
        mostrar=false;
    }

    return mostrar;
}

bool c_reuniones::buscarID(int &ID){
    bool encontrado=false;
    if(this->ID()==ID){
        encontrado=true;
    }
    return encontrado;
}

c_reuniones::c_reuniones(){ }

c_reuniones::c_reuniones(int ID,int ID_alumno,std::string resumen)://,QDateTime fecha):
               ID_(ID),ID_alumno_(ID_alumno), resumen_(resumen), borrado_(false)
               /*fecha_(fecha)/{this->setBorrado(false);}

c_reuniones::~c_reuniones()
{

}
*/

#include "gestionaralumno.h"
#include "ui_gestionaralumno.h"



gestionarAlumno::gestionarAlumno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestionarAlumno)
{
    ui->setupUi(this);
}

gestionarAlumno::~gestionarAlumno()
{
    gestor v1;
    v1.setControllers(*controller_);
    v1.exec();
    delete ui;
}

void gestionarAlumno::setController (MainController &controller){
    controller_=&controller;

}

//Datos al iniciar
void gestionarAlumno::inicial(){
    this->showAlumno();
    ui->editAlumno->setEnabled(false);
    ui->btnAcpetar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(false);
    ui->btnBorrar->setEnabled(false);
    ui->btnNuevo->setEnabled(true);
    ui->tableAlumno->setEnabled(true);
}

//Limpiar las etiquetas
void gestionarAlumno::limpiarLabel(){
    ui->txtNombre->clear();
    ui->txtTelefono->clear();
    ui->txtemail->clear();

}
//Muestra los alumnos
void gestionarAlumno::showAlumno(){
    rellenarTabla(controller_->getAlumnos(), ui->tableAlumno, &criterio);
}
//Muestra las etiquetas
void gestionarAlumno::showLabel(){
    qDebug()<<"current: "<<ui->tableAlumno->currentRow();
    if (ui->tableAlumno->rowCount()>0){
        QString ID = ui->tableAlumno->item(ui->tableAlumno->currentRow(),3)->text();
        int seleccionado = ID.toInt();
        encontrarID(controller_->getAlumnos(), &seleccionado);
        ui->txtTelefono->setText(QString::fromStdString(controller_->getAlumnos().at(seleccionado).telefono()));
        ui->txtNombre->setText(QString::fromStdString(controller_->getAlumnos().at(seleccionado).nombre()));
        ui->txtemail->setText(QString::fromStdString(controller_->getAlumnos().at(seleccionado).email()));
        //ui->dateEdit->setDate(QDate(controller_->getalumnos().at(seleccionado).getFecha().getDia(),seleccionado.getFecha().getMes(),seleccionado.getFecha().getAnio()));
        //ui->dateEdit_2->setDate(QDate(controller_->getalumnos().at(seleccionado.getFecha().getDia(),seleccionado.getFecha().getMes(),seleccionado.getFecha().getAnio()));
        ui->btnModificar->setEnabled(true);
        ui->btnBorrar->setEnabled(true);
    }
}
// Al añadir un nuevo usuario
void gestionarAlumno::nuevo(){
    opcion=1;
    ui->editAlumno->setEnabled(true);
    ui->tableAlumno->clearSelection();
    ui->tableAlumno->setEnabled(false);
    ui->btnModificar->setEnabled(false);
    ui->btnBorrar->setEnabled(false);
    ui->btnAcpetar->setEnabled(true);
    ui->btnCancelar->setEnabled(true);
    ui->btnNuevo->setEnabled(false);
    //this->inicial();
    this->limpiarLabel();

    ui->txtNombre->setFocus();
}

//Al modificar
void gestionarAlumno::modificar(){
    QModelIndexList selectedList = ui->tableAlumno->selectionModel()->selectedRows();
    if (!selectedList.empty()){
        opcion=2;
        ui->editAlumno->setEnabled(true);
        ui->tableAlumno->setEnabled(false);
        ui->txtNombre->setFocus();
        ui->btnAcpetar->setEnabled(true);
        ui->btnCancelar->setEnabled(true);
        ui->btnModificar->setEnabled(false);
        ui->btnBorrar->setEnabled(false);
        ui->btnNuevo->setEnabled(false);
    }
}

void gestionarAlumno::borrar(){

    QString ID = ui->tableAlumno->item(ui->tableAlumno->currentRow(),3)->text();
    int seleccionado = ID.toInt();
    encontrarID(controller_->getAlumnos(), &seleccionado);

    ui->editAlumno->setEnabled(false);
    ui->tableAlumno->setEnabled(false);
    ui->btnAcpetar->setEnabled(false);
    ui->btnCancelar->setEnabled(false);
    ui->btnModificar->setEnabled(false);
    ui->btnBorrar->setEnabled(false);
    ui->btnNuevo->setEnabled(false);
    QMessageBox::StandardButton btnBorrar;
    btnBorrar = QMessageBox::question(this, "", "Está seguro que desea eliminar el alumno: " + QString::fromStdString(controller_->getAlumnos().at(seleccionado).nombre()), QMessageBox::Yes | QMessageBox:: No);
    if(btnBorrar == QMessageBox::Yes){
        c_alumno copyBorrar = controller_->getAlumnos().at(seleccionado);
        copyBorrar.setBorrado(true);
        controller_->modificarAlumnos(seleccionado, copyBorrar);
        for(size_t i=0; i<controller_->getAlumnos().count(); i++){
            if(controller_->getAlumnos().at(i).ID()==ID.toInt()){
                c_alumno copyUser = controller_->getAlumnos().at(i);
                copyUser.setBorrado(true);
                controller_->modificarAlumnos(i, copyUser);
            }
        }
        //this->inicial();
        this->limpiarLabel();
    }else if(btnBorrar == QMessageBox::No){
        //this->inicial();
        this->limpiarLabel();
    }
}

void gestionarAlumno::aceptar(){
    switch (opcion) {
    case 1:{
        if(ui->txtNombre->text().isEmpty() || ui->txtTelefono->text().isEmpty() || ui->txtemail->text().isEmpty()){
            QMessageBox::information(this, "", "Debe rellenar todos los campos");
        }else{
            c_alumno nuevo;
            controller_->setUltimoIDalumno();
            nuevo.setID(controller_->getUltimoIDalumno());
            nuevo.setBorrado(false);
            nuevo.setNombre(ui->txtNombre->text().toStdString());
            nuevo.setTelefono(ui->txtTelefono->text().toStdString());
            nuevo.SetEmail(ui->txtemail->text().toStdString());
            //nuevo.setFechaOrdinaria();
            controller_->setAlumnos(nuevo);
            ui->tableAlumno->selectRow(ui->tableAlumno->rowCount()-1);

        }
        break;
    }
    case 2:{
        QString ID = ui->tableAlumno->item(ui->tableAlumno->currentRow(),3)->text();
        int seleccionado = ID.toInt();
        encontrarID(controller_->getAlumnos(), &seleccionado);
        int fila = ui->tableAlumno->currentRow();

        if(ui->txtNombre->text().isEmpty() || ui->txtTelefono->text().isEmpty() || ui->txtemail->text().isEmpty()){
            QMessageBox::information(this, "", "Todos los campos deben estár rellenos");
        }else{
            c_alumno modificado;
            modificado=controller_->getAlumnos().at(seleccionado);
            modificado.setNombre(ui->txtNombre->text().toStdString());
            modificado.setTelefono(ui->txtTelefono->text().toStdString());
            modificado.SetEmail(ui->txtemail->text().toStdString());
            //modificado.setFechaOrdinaria();
            controller_->modificarAlumnos(seleccionado, modificado);
            ui->tableAlumno->selectRow(fila);
        }
        break;
    }
    default:
        break;
    }
}

void gestionarAlumno::cancelar(){
   // this->inicial();
    this->limpiarLabel();
}

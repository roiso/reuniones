#include <iostream>
#include "fecha.h"


Fecha::Fecha() : dias(0), mess(0), anios(0) {}

Fecha::Fecha(size_t dia, size_t mes, int anio)
    : dias(dia), mess(mes), anios(anio) {}

Fecha::~Fecha() {}

//Contiene los datos de la fecha
void Fecha::setFecha(size_t dia, size_t mes, int anio) {
  this->dias = dia;
  this->mess = mes;
  this->anios = anio;
}


void Fecha::setDia(size_t dia) {
  this->dias = dia;
}


void Fecha::setMes(size_t mes) {
  this->mess = mes;
}


void Fecha::setAnio(int anio) {
  this->anios = anio;
}

//Obtienes el dia

size_t Fecha::getDia() {
  return this->dias;
}

//Obtienes el mes

size_t Fecha::getMes() {
  return this->mess;
}

// Obtienes el anio

int Fecha::getAnio() {
  return this->anios;
}



#ifndef FECHA_H
#define FECHA_H

#include <stddef.h>

//Clase fecha

class Fecha {
 private:

    std::size_t dias;

    std::size_t mess;

    int anios;

 public:

    Fecha();

    Fecha(std::size_t dia, std::size_t mes, int anio);

    ~Fecha();


    void setFecha(std::size_t dia, std::size_t mes, int anio);

    void setDia(std::size_t dia);

    void setMes(std::size_t mes);

    void setAnio(int anio);

    std::size_t getDia();

    std::size_t getMes();

    int getAnio();
};

#endif // FECHA_H

#ifndef ALMACEN_H
#define ALMACEN_H
#include "camion.h"


struct Almacen
{
    int cantMasa;
    int cantChoco;
    Almacen();
    void cargarCamion(Carga* carga);
};

#endif // ALMACEN_H

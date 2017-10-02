#ifndef ALMACEN_H
#define ALMACEN_H
#include "camion.h"


struct Almacen
{
public:
    Almacen();
    void cargarCamion(Carga* carga);
};

#endif // ALMACEN_H

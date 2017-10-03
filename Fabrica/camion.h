#ifndef CAMION_H
#define CAMION_H
#include "cola.h"


struct Camion{
    Camion();
    Cola* pedidos = new Cola();
    bool play;
};

#endif // CAMION_H

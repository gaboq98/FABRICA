#ifndef CAMION_H
#define CAMION_H
#include "cola.h"


struct Camion{
    Camion();
    Cola* pedidos = new Cola();
    bool encendido;
    void recibirPedido(int maquina, int cantidad);
    int entregar(int maquina, int cantidad);
};

#endif // CAMION_H

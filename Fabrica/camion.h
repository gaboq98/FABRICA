#ifndef CAMION_H
#define CAMION_H
#include "cola.h"


struct Camion{
    Camion();
    Cola* pedidos = new Cola();
    bool encendido;
    int entregar(int maquina, int cantidad);
    void recibirPedido(int maquina, int cantidad);
};

#endif // CAMION_H

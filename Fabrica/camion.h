#ifndef CAMION_H
#define CAMION_H
#include "cola.h"
#include <QDebug>


struct Camion{
    Camion();
    Cola* pedidos;
    bool encendido;
    int entregar(int maquina, int cantidad);
    void recibirPedido(int maquina, int cantidad);
};

#endif // CAMION_H

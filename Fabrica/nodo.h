#ifndef NODO_H
#define NODO_H
#include "camionthread.h"

struct Nodo
{
    int paquete;
    int cantidad;
    int probabilidad;
    Camion *camion;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo();
    Nodo(int pack, int cant, int prob, Camion *c);
};

#endif // NODO_H

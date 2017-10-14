#include "nodo.h"

Nodo::Nodo()
{
    siguiente = anterior = nullptr;
    probabilidad = 0;
}

Nodo::Nodo(int pack, int cant, int prob, Camion *c)
{
    paquete = pack;
    cantidad = cant;
    camion = c;
    probabilidad = prob;
    siguiente = anterior = nullptr;
}

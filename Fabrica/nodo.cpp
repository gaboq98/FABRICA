#include "nodo.h"

Nodo::Nodo()
{
    siguiente = anterior = nullptr;
}

Nodo::Nodo(int pack, int cant, Camion *c)
{
    paquete = pack;
    cantidad = cant;
    camion = c;
    siguiente = anterior = nullptr;
}

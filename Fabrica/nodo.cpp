#include "nodo.h"

Nodo::Nodo()
{
    siguiente = anterior = nullptr;
}

Nodo::Nodo(int pack, int cant)
{
    paquete = pack;
    cantidad = cant;
    siguiente = anterior = nullptr;
}

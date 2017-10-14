#include "nodo.h"

//DESCRIPCION: constructor
Nodo::Nodo()
{
    siguiente = anterior = nullptr;
    probabilidad = 0;
}

//ENTRADAS: dantidad de paquetes, numero de paquetes a crear, camion c
//DESCRIPCION: constructor con parametros donde asigna valores
Nodo::Nodo(int pack, int cant, int prob, Camion *c)
{
    paquete = pack;
    cantidad = cant;
    camion = c;
    probabilidad = prob;
    siguiente = anterior = nullptr;
}

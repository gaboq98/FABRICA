#include "nodo.h"

//DESCRIPCION: constructor
Nodo::Nodo()
{
    siguiente = anterior = nullptr;
}


//ENTRADAS: dantidad de paquetes, numero de paquetes a crear, camion c
//DESCRIPCION: constructor con parametros donde asigna valores
Nodo::Nodo(int pack, int cant, Camion *c)
{
    paquete = pack;
    cantidad = cant;
    camion = c;
    siguiente = anterior = nullptr;
}

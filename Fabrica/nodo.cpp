#include "nodo.h"

Nodo::Nodo()
{

}

Nodo::Nodo(int _cantidad,int _destino){
    cantidad = _cantidad;
    destino = _destino;
    siguiente = NULL;
}

#include "camion.h"

Camion::Camion()
{
    frente = fondo = NULL;
}

bool Camion::isEmpty(){
    return frente == NULL;
}

void Camion::encolar(int dest, int cant){
    if(isEmpty())
        frente = fondo = new Carga(dest, cant);
    else{
        fondo->siguiente = new Carga(dest, cant);
        fondo = fondo->siguiente;
    }
}

Carga* Camion::desencolar(){
    if(isEmpty())
        return NULL;
    else if(frente == fondo){
        Carga* borrado = fondo;
        frente = fondo = NULL;
        return borrado;
    }
}

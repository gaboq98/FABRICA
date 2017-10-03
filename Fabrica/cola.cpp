#include "cola.h"

Cola::Cola(){
   fondo = frente = NULL;
}

bool Cola::isEmpty(){
    return frente == NULL;
}

Nodo *Cola::desencolar(){
    if(isEmpty())
        return NULL;
    else if(frente == fondo){
        Nodo* borrado = frente;
        frente = fondo = NULL;
        return borrado;
    }else{
         Nodo* borrado = frente;
         frente = frente->siguiente;
         borrado->siguiente = NULL;
         return borrado;
    }
}

void Cola::encolar(QString tipo, int cant, int dest){
    if(isEmpty())
        frente = fondo = new Nodo(tipo,cant,dest);
    else{
        fondo->siguiente = new Nodo(tipo,cant,dest);
        fondo = fondo->siguiente;
    }
}

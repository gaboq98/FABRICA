#ifndef COLA_H
#define COLA_H
#include "nodo.h"


struct Cola
{
    Nodo* frente;
    Nodo* fondo;
    Cola();
    bool isEmpty();

    void encolar(int cant, int dest);
    Nodo* desencolar();
};

#endif // COLA_H

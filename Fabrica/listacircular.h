#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "nodo.h"


struct ListaCircular
{
    Nodo *pn;
    Nodo *un;
    int length;
    ListaCircular();
    void insertar(int pack, int cant, Camion *c);
    Nodo* obtener(int index);
};

#endif // LISTACIRCULAR_H

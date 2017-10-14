#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "nodo.h"
#include <QString>


struct ListaCircular
{
    Nodo *pn;
    Nodo *un;
    int length;
    ListaCircular();
    void insertar(int pack, int cant, int prob, CamionThread *c);
    Nodo* obtener(int index);
    QString imprimir();
};

#endif // LISTACIRCULAR_H

#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H
#include "nodo.h"

struct MezcladoraMasa{
    int maximo;
    int minimo;
    int cantidad;
    int ups; // unidades por segundo
    MezcladoraMasa();
    MezcladoraMasa(int min, int max);
    void insertarMasa(int cant);
    Nodo* procesa();
    int pedir(int cant);
};

#endif // MEZCLADORAMASA_H

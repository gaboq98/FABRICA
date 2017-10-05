#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H
#include "nodo.h"
#include "camion.h"


struct MezcladoraMasa{
    int maximo;
    int minimo;
    int cantidad;
    Camion *cola;
    int ups; // unidades por segundo
    int maquina;
    MezcladoraMasa();
    MezcladoraMasa(Camion cola, int maquina);
    MezcladoraMasa(int min, int max);
    void insertarMasa(int cant);
    Nodo* procesa();
    void pedir(int cant);
};

#endif // MEZCLADORAMASA_H

#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H
#include "nodo.h"
#include "camion.h"

struct MezcladoraMasa{
    int maximo;
    int minimo;
    int cantidad;
    int maquina;
    Camion *camion;
    int ups; // unidades por segundo
    bool encendido;
    MezcladoraMasa();

    void insertarMasa(int cant);
    void procesa();
    void pedir(int cant);
};

#endif // MEZCLADORAMASA_H

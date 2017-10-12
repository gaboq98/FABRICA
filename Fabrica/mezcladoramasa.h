#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H
#include "nodo.h"
#include "camion.h"
#include "QDebug"
#include <QtCore>

struct MezcladoraMasa{
    int maximo;
    int minimo;
    int cantidad;
    int maquina;
    int ups; // unidades por segundo
    bool encendido;
    int procesado;
    MezcladoraMasa();

    void insertarMasa(int cant);
    void procesa();
    void pedir(int cant);
};

#endif // MEZCLADORAMASA_H

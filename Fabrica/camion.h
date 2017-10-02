#ifndef CAMION_H
#define CAMION_H
#include <cstddef>

struct Carga{
    int destino;
    int cantidad;
    Carga* siguiente;
    bool estaCargado;

    Carga(){}

    Carga(int dest, int cant){
        destino = dest;
        cantidad = cant;
        estaCargado = false;
    }

};

struct Camion
{
    Carga* frente;
    Carga* fondo;

    void encolar(int dest, int cant);
    Carga* desencolar();
    bool isEmpty();

    Camion();
};

#endif // CAMION_H

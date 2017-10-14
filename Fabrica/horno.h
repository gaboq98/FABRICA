#ifndef HORNO_H
#define HORNO_H
#include "QDebug"
#include <conio.h>
#include <windows.h>

struct Horno
{
public:
    Horno();
    int maximo;
    int actual;
    int tiempo;
    bool encendido;
    int *galletas;
    int total;
    bool hornea();
    int contador;
    bool cocinando;
    void reset();

};

#endif // HORNO_H

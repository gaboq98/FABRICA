#ifndef EMPACADORA_H
#define EMPACADORA_H
#include <QVector>
#include "listacircular.h"


struct Empacadora
{
    int *banda;
    QVector<int> tiposDePaquete;
    ListaCircular *lista;
    int tiempo;
    Empacadora();
    void empaca();
};

#endif // EMPACADORA_H

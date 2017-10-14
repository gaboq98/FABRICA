#ifndef EMPACADORA_H
#define EMPACADORA_H
#include <QVector>
#include "listacircular.h"


struct Empacadora
{
    int *banda;
    QVector<int> totalpack;
    ListaCircular *lista;
    int tiempo;
    Empacadora();
    int empaca();
    void set_lista(ListaCircular* l);
};

#endif // EMPACADORA_H

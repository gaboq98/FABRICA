#ifndef NODO_H
#define NODO_H
#include <QApplication>


struct Nodo
{
    QString tipo;
    int cantidad;
    int destino;
    Nodo* siguiente;
    Nodo();
};

#endif // NODO_H

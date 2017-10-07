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
    Nodo(int _cantidad,int _destino);
};

#endif // NODO_H

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
    Nodo(int cantidad, int destino);
    Nodo(QString _tipo, int _cantidad,int _destino);
    Nodo(QString _tipo, int _cantidad);
};

#endif // NODO_H

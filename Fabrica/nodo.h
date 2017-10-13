#ifndef NODO_H
#define NODO_H


struct Nodo
{
    int paquete;
    int cantidad;
    Nodo *siguiente;
    Nodo *anterior;
    Nodo();
    Nodo(int pack, int cant);
};

#endif // NODO_H

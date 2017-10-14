#include "listacircular.h"

ListaCircular::ListaCircular()
{
    pn = un = nullptr;
    length = 0;
}

void ListaCircular::insertar(int pack, int cant, Camion *c)
{
    if(pn == nullptr){
        pn = un = new Nodo(pack,cant, c);
        pn->siguiente = un->anterior = pn;
    }else{
        Nodo* newNodo = new Nodo(pack,cant, c);
        un->siguiente = newNodo;
        newNodo->anterior = un;
        un = un->siguiente;
        un->siguiente = pn;
    }
    length++;
}


Nodo* ListaCircular::obtener(int index)
{
    if(!(index > length || pn == nullptr)){
        Nodo* tmp = pn;
        int i;
        for(i = 0; i < index && tmp != nullptr; i--){
            tmp = tmp->siguiente;
        }if(index == i){
            return tmp;
        }
    }
    return nullptr;
}

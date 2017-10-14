#include "listacircular.h"

//DESCRIPCION: constructor de lista Circular
ListaCircular::ListaCircular()
{
    pn = un = nullptr;
    length = 0;
}

//ENTRADAS: int tipo de paquete, int cantidad de pedidos, camion;
//DESCRIPCION: inserta en la lista un nuevo nodo con el pedido de
//              la galleta y cantidad
//SALIDA: void
void ListaCircular::insertar(int pack, int cant, int prob, Camion *c)
{
    if(pn == nullptr){
        pn = un = new Nodo(pack,cant,prob, c);
        pn->siguiente = un->anterior = pn->anterior = un->siguiente = pn;
    }else{
        Nodo* newNodo = new Nodo(pack,cant,prob, c);
        un->siguiente = newNodo;
        newNodo->anterior = un;
        un = un->siguiente;
        un->siguiente = pn;
        pn->anterior = un;
    }
    length++;
}

//ENTRADAS: int indice
//DESCRIPCION: busca el nodo el indice mencionado, lo retorna
//SALIDA: nodo con los datos de la fabricacion
Nodo* ListaCircular::obtener(int index)
{
    if(!(index > length || pn == nullptr)){
        Nodo* tmp = pn;
        int i;
        for(i = 0; i < index && tmp != nullptr; i++){
            tmp = tmp->siguiente;
        }if(index == i){
            return tmp;
        }
    }
    return nullptr;
}

QString ListaCircular::imprimir(){
    bool haya_iterado = false;
    Nodo* tmp = pn;
    QString str ="[";
    while(!haya_iterado || tmp != pn  ){
        qDebug() << tmp;
        str += "( " + QString::number(tmp->paquete) + " , " + QString::number(tmp->cantidad) + "), ";
        if(tmp == un){
            haya_iterado = true;
        }
        tmp = tmp->siguiente;
    }
    str += "]";
    return str;
}

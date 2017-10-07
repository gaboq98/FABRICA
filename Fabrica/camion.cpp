#include "camion.h"
#include <QDebug>


int Camion :: entregar(int maquina, int cantidad) {
    if(encendido) {
        return cantidad;
    }

}

void Camion::recibirPedido(int maquina, int cantidad)
{
    if(encendido) {
        Nodo* temp = new Nodo(maquina, cantidad);
        pedidos->encolar(cantidad, maquina);
    }
}

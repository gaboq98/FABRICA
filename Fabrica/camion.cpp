#include "camion.h"
#include <QDebug>


void Camion::recibirPedido(int maquina, int cantidad)
{
    pedidos->encolar(cantidad, maquina);
}

int Camion :: entregar(int maquina, int cantidad) {
    if(encendido) {
        return cantidad;
    }

}

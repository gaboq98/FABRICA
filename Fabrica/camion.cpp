#include "camion.h"


Camion::Camion()
{
    pedidos = new Cola();
    encendido = true;
}

int Camion :: entregar(int maquina, int cantidad) {
    if(encendido) {
        return cantidad;
    }

}

void Camion::recibirPedido(int maquina, int cantidad)
{
    if(encendido) {
        pedidos->encolar(cantidad, maquina);
        qDebug() << "camion" << cantidad;
    }
}

#include "mezcladoramasa.h"

MezcladoraMasa::MezcladoraMasa(){
    ups = cantidad = minimo = maximo = 0;
}

MezcladoraMasa::MezcladoraMasa(Camion _cola, int _maquina)
{
    cola = _cola;
    maquina = _maquina;
}

MezcladoraMasa::MezcladoraMasa(int min, int max){
    minimo = min;
    maximo = max;
}

void MezcladoraMasa::insertarMasa(int cant){
    cantidad += cant;
}

Nodo* MezcladoraMasa::procesa(){
    cantidad -= ups;
    return NULL;
}

void MezcladoraMasa::pedir(int cantidad) {
    while (true) {
        if(cantidad < minimo) {
            cola->recibirPedido(maquina ,cantidad);
        } else {
            return NULL;
        }
    }
}

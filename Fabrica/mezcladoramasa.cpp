#include "mezcladoramasa.h"

MezcladoraMasa::MezcladoraMasa(){
    ups = cantidad = minimo = maximo = 0;
}


void MezcladoraMasa::insertarMasa(int cant){
    cantidad += cant;
}

void MezcladoraMasa::procesa(){
    cantidad -= ups;
    pedir(maximo-minimo);
}

void MezcladoraMasa::pedir(int cantidad) {
    if(encendido) {
        if(cantidad <= minimo) {
            camion->recibirPedido(maquina, cantidad);
        }
    }
}

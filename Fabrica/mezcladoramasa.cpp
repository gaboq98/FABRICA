#include "mezcladoramasa.h"

MezcladoraMasa::MezcladoraMasa(){
    ups = cantidad = minimo = maximo = 0;
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

int MezcladoraMasa::pedir(int cantidad) {
    if(cantidad < minimo) {
        return cantidad;
    } else {
        return NULL;
    }
}

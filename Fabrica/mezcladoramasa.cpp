#include "mezcladoramasa.h"

MezcladoraMasa::MezcladoraMasa(){
    ups = cantidad = minimo = maximo = procesado = 0;
    encendido = true;
}

void MezcladoraMasa::insertarMasa(int cant){
    if(encendido) {
        cantidad += cant;
    }
}

void MezcladoraMasa::procesa(){
    if(encendido) {
        pedir(maximo-minimo);
        cantidad -= ups;
    }
}

void MezcladoraMasa::pedir(int cantidad) {
    if(encendido) {
        if(this->cantidad <= minimo) {
            this->cantidad = cantidad;
        }
    }
}

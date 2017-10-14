#include "mezcladoramasa.h"


//DESCRIPCION: constructor de la mezcladora masa
MezcladoraMasa::MezcladoraMasa(){
    ups = cantidad = minimo = maximo = procesado = 0;
    encendido = true;
}

//ENTRADAS: int cantidad de masa
//DESCRIPCION: inserta la masa a la
//             mezcladora para ser procesado
//SALIDA: void
void MezcladoraMasa::insertarMasa(int cant){
    if(encendido) {
        cantidad += cant;
    }
}


//DESCRIPCION: procesa la masa y la disminuye gradualmente
//SALIDA: void
void MezcladoraMasa::procesa(){
    if(encendido) {
        pedir(maximo-minimo);
        cantidad -= ups;
    }
}


//ENTRADAS: int cantidad de masa
//DESCRIPCION: pide masa para seguir trabajando
//SALIDA: void
void MezcladoraMasa::pedir(int cantidad) {
    if(encendido) {
        if(this->cantidad <= minimo) {
            this->cantidad = cantidad;
        }
    }
}

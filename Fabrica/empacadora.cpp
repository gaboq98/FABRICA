#include "empacadora.h"

//DESCRIPCION: constructor de la empacadora
Empacadora::Empacadora()
{
    banda = nullptr;
}

//DESCRIPCION: genera un numero random con el cual busca
//             cual paquete coresponde con el numero,
//             aumenta la cantidad de paquetes del camion
//SALIDA: int del paquete actual empacado

int Empacadora::empaca()
{
    int result = 0;
    int num = rand() % 100;
    int acumulador = 0;
    for(int i = 0; i < lista->length; i++){
        acumulador += lista->obtener(i)->probabilidad;
        if(num <= acumulador){
            result = lista->obtener(i)->paquete;
            lista->obtener(i)->camion->actual++;
            totalpack[i]++;
            break;
        }
    }
    *banda -= result;
    return result;
}


//ENTRADAS: puntero a lista circular de la empacadora
//DESCRIPCION: asigna la lista de la empacadora y asigna
//             el tamaño del arreglo de las cantidades totales
//             por tipo de galleta.
void Empacadora::set_lista(ListaCircular* l)
{
    lista = l;
    totalpack.reserve(lista->length);
}

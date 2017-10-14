#include "empacadora.h"

Empacadora::Empacadora()
{
    banda = nullptr;
}

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

void Empacadora::set_lista(ListaCircular* l)
{
    lista = l;
    totalpack.reserve(lista->length);
}

#include "empacadora.h"

Empacadora::Empacadora()
{
    banda = nullptr;
}

void Empacadora::empaca()
{
    int num = rand() % 100;
    int acumulador = 0;
    for(int i = 0; i < lista->length; i++){
        acumulador += lista->obtener(i)->probabilidad;
        if(num <= acumulador){
            result = lista->obtener(i)->paquete;
            //lista->obtener(i)->camion->actual++;
            break;
        }
    }
    *banda -= result;
}

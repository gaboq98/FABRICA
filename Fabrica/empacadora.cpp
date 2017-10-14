#include "empacadora.h"

//DESCRIPCION: constructore de la empacadora
Empacadora::Empacadora()
{
    banda = nullptr;
}


//ENTRADA:
//DESCRIPCION: genera un numero random con el cual busca
//             cual paquete coresponde con el numero,
//             aumenta la cantidad de paquetes dl camion
//SALIDA: void
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

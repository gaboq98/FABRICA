#include "empacadora.h"

Empacadora::Empacadora()
{
    //banda = nullptr;
}

int Empacadora::empaca()
{
    qDebug() << "banda: " << *banda;
    int result = 0;
    int acumulador = 0;
    int num = rand() % 100;
    for(int i = 0; i < lista->length; i++){
        acumulador += lista->obtener(i)->probabilidad;
        qDebug() << "pribabilidad: " << acumulador;
        qDebug() << num;
        if(num <= acumulador){
            result = lista->obtener(i)->paquete;
            if(*banda > result){
                lista->obtener(i)->camion->actual++;
                totalpack[i]++;
                *banda -= result;
                break;
            }
        }
    }
    return result;
}

void Empacadora::set_lista(ListaCircular* l)
{
    lista = l;
    totalpack.resize(lista->length);
}

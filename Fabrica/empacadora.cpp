#include "empacadora.h"

Empacadora::Empacadora()
{
    banda = 0;
}

int Empacadora::empaca()
{
    int num = rand() % tiposDePaquete.size();
    int result;
    for(int i = 0; i < tiposDePaquete.size(); i++){
        if(i == num)
            result = tiposDePaquete[i];
    }
    banda -= result;
    return result;
}

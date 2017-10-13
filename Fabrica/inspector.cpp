#include "inspector.h"

Inspector::Inspector()
{
    aprobado = rechazado = porcentaje = 0;
    detenerse = false;
}

int Inspector::recibe()
{
    if(!detenerse) {
        int number = rand() % 100;
        if(number > porcentaje){
            aprobado++;
            return 1;
        }else{
            rechazado++;
            return 0;
        }
    }
    return 0;
}

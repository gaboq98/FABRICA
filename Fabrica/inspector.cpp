#include "inspector.h"

Inspector::Inspector()
{
    aprobado = rechazado = porcentaje = 0;
}

int Inspector::recibe()
{
    int number = rand() % 100;
    if(number > porcentaje){
        aprobado++;
        return 1;
    }else{
        rechazado++;
        return 0;
    }
}

#include "inspector.h"


//DESCRIPCION: constructor del inspector
Inspector::Inspector()
{
    aprobado = rechazado = porcentaje = 0;
    detenerse = false;
}


//ENTRADAS:
//DESCRIPCION: genera un numero random donde
//             se entera si se aprueba o se rechaza la galleta
//SALIDA: retorna 1 si la galleta fue aprobada o 0 si rechazada
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

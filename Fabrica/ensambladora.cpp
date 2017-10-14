#include "ensambladora.h"

//DESCRIPCION: constructor de la ensambladora
Ensambladora::Ensambladora()
{
    encendido = true;
    procesado = 0;
}


//DESCRIPCION: aumenta el valor del contador de galletas
//             procesadas y disminuye el valoren las
//             respectivas cintas de datos
//SALIDA: void
void Ensambladora::procesa()
{
    if(encendido) {
        if((*masa != 0) | (*chocolate != 0)) {
            *masa -= mpg * gps;
            *chocolate -= cpg * gps;
            procesado += gps;
        }
    }
}

#include "ensambladora.h"

Ensambladora::Ensambladora()
{
    encendido = true;
    procesado = 0;
}

void Ensambladora::procesa()
{
    if(encendido) {
        qDebug() << *chocolate;
        if((*masa != 0) | (*chocolate != 0)) {
            *masa -= mpg * gps;
            *chocolate -= cpg * gps;
            procesado += gps;
        }
    }
}

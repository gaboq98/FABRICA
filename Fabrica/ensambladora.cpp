#include "ensambladora.h"

Ensambladora::Ensambladora()
{
    encendido = true;
}

void Ensambladora::procesa()
{
    if(encendido) {
        masa =- mpg * gps;
        chocolate =- cpg * gps;
        procesado += gps;
    }

}

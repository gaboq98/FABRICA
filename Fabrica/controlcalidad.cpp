#include "controlcalidad.h"

//DESCRIPCION: constructor de control, de calidad
ControlCalidad::ControlCalidad()
{
    salida = 0;
    inspec_1 = new Inspector();
    inspec_2 = new Inspector();
}


//DESCRIPCION: avanzan galletas en la cinta del control de calidad
//             si la banda tiene más de 2 galletas adentro
//             suma las galletas a la cinta de resultado
//SALIDAS: void
void ControlCalidad::avanza(){
    if(*banda < 2)
        return;
    int result = 0;
    result += inspec_1->recibe();
    result += inspec_2->recibe();
    salida += result;
}

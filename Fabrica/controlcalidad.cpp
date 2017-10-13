#include "controlcalidad.h"

ControlCalidad::ControlCalidad()
{
    salida = 0;
    inspec_1 = new Inspector();
    inspec_2 = new Inspector();
}

void ControlCalidad::avanza(){
    if(*banda < 2)
        return;
    int result = 0;
    result += inspec_1->recibe();
    result += inspec_2->recibe();
    salida += result;
}

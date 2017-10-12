#include "controlcalidad.h"

ControlCalidad::ControlCalidad()
{
    banda = salida = 0;
    inspec_1 = new Inspector();
    inspec_2 = new Inspector();
}

void ControlCalidad::avanza(){
    int result = 0;
    result += inspec_1->recibe();
    result += inspec_2->recibe();
    salida += result;
}

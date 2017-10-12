#include "controlcalidad.h"

ControlCalidad::ControlCalidad()
{
    banda = 0;
    inspec_1 = new Inspector();
    inspec_2 = new Inspector();
}

int ControlCalidad::avanza(){
    int result = 0;
    result += inspec_1->recibe();
    result += inspec_2->recibe();
    return result;
}

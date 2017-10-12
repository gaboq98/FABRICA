#ifndef CONTROLCALIDAD_H
#define CONTROLCALIDAD_H
#include "inspector.h"


struct ControlCalidad
{
    int banda;
    Inspector *inspec_1;
    Inspector *inspec_2;
    ControlCalidad();
    int avanza();
};

#endif // CONTROLCALIDAD_H

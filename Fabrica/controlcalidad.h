#ifndef CONTROLCALIDAD_H
#define CONTROLCALIDAD_H
#include "inspector.h"


struct ControlCalidad
{
    int banda;
    int salida;
    Inspector *inspec_1;
    Inspector *inspec_2;
    ControlCalidad();
    void avanza();
};

#endif // CONTROLCALIDAD_H

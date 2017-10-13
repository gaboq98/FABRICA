#ifndef INSPECTOR_H
#define INSPECTOR_H
#include <cstdlib>


struct Inspector
{
    int porcentaje;
    int aprobado;
    int rechazado;
    bool detenerse;
    Inspector();
    int recibe();
};

#endif // INSPECTOR_H

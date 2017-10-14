#include "camion.h"

Camion::Camion()
{
    actual = maximo = tiempo = 0;
}

int Camion::entregar()
{
    actual = 0;
    return maximo;
}

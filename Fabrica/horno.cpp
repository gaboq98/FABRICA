#include "horno.h"

Horno::Horno()
{
    maximo = actual = tiempo = total = contador = 0;
    encendido = true;
}

bool Horno::hornea()
{
    if(encendido) {
        if(!cocinando) {
            if(actual >= maximo) {
                actual = 0;
                cocinando = true;
                return true;
            }
            actual++;
            total++;
            *galletas -= 1;
            return false;
        } else {
            if(contador == tiempo) {
                cocinando = false;
                contador = 0;
            } else {
                contador++;
            }
        }
    }
    return false;
}

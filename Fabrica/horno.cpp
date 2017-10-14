#include "horno.h"


//DESCRIPCION: construccion de horno, inicializa las variables
Horno::Horno()
{
    maximo = actual = tiempo = total = contador = 0;
    encendido = true;
}


//ENTRADAS:
//DESCRIPCION: funcion hornea es agregar galletas hasta llenarse
//             la bandeja, cuando eso sucede retorna true para
//             empezar a hornear las galletas
//SALIDA: booleano
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


void Horno::reset()
{
    actual = 0;
    contador = 0;
    total = 0;
}

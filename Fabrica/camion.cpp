#include "camion.h"


//DESCRIPCION: Constructor vacío de camion
//             inicializa todos los numeros en cero;
Camion::Camion()
{
    actual = maximo = tiempo = 0;
}

//ENTRADAS:
//DESCRIPCION: funcion que entrega la carga a su destino
//             su actual vuelve a ser cero
//SALIDAS: el maximo del camion
int Camion::entregar()
{
    actual = 0;
    return maximo;
}

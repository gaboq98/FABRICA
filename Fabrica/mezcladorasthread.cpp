#include "mezcladorasthread.h"


//DESCRIPCION: constructor
MezcladorasThread::MezcladorasThread()
{
    encendido = true;
    detenerse = false;
}


//DESCRIPCION: constructor con mezclador como parametro
MezcladorasThread::MezcladorasThread(MezcladoraMasa *m1)
{
    encendido = true;
    detenerse = false;
    mezcladora1 = m1;

}

//ENTRADAS:
//DESCRIPCION: implementacion del metodo run
//             procesa mientras esté encendido
//             emite la cantidad producida en el segundo
//             emite la orden de poner el valor de la banda
//SALIDA: void
void MezcladorasThread::run()
{
    while (encendido) {
        if(detenerse)
            sleep(0.5);
        else {
            mezcladora1->procesa();
            emit entregarM1(mezcladora1->cantidad);
            mezcladora1->procesado += mezcladora1->ups;
            emit banda(mezcladora1->ups);
            emit recibeBanda();
            sleep(1);
        }        
    }
}

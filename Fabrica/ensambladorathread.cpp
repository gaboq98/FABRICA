#include "ensambladorathread.h"


//DESCRIPCION: constructor de la ensambladora (hilo)
//             inicializa lis valores booleanos
EnsambladoraThread::EnsambladoraThread()
{
    encendido = true;
    detenerse = false;
}

//ENTRADAS: puntero a una ensambladora
//          inicializa ciertos valores
EnsambladoraThread::EnsambladoraThread(Ensambladora *e)
{
    encendido = true;
    detenerse = false;
    ensambladora = e;
}


//DESCRIPCION: metodo run del hilo, cuando el hilo este encendido ejecuta la
//             funcion procesa de la ensambladora, despues de eso, emite las
//             galletas de la ensambladoras para representarlas en pantalla
//SALIDA: void
void EnsambladoraThread::run()
{
    while (encendido) {
        if(detenerse) {
            sleep(0.5);
        } else {
            ensambladora->procesa();
            emit procesadoEnsambladora(ensambladora->gps);
            sleep(1);
        }
    }
}

#include "ensambladorathread.h"

EnsambladoraThread::EnsambladoraThread()
{
    encendido = true;
    detenerse = false;
}

EnsambladoraThread::EnsambladoraThread(Ensambladora *e)
{
    encendido = true;
    detenerse = false;
    ensambladora = e;
}

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

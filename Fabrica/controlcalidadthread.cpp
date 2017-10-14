#include "controlcalidadthread.h"

ControlCalidadThread::ControlCalidadThread()
{
    encendido = true;
    detenerse = false;
}

ControlCalidadThread::ControlCalidadThread(ControlCalidad* c)
{
    controlC = c;
    encendido = true;
    detenerse = false;
}

void ControlCalidadThread::run()
{
    while (encendido) {
        if(detenerse) {
            sleep(0.5);
        } else {
            controlC->avanza();
            emit(entregaApr1(controlC->inspec_1->aprobado));
            emit(entregaApr2(controlC->inspec_2->aprobado));
            emit(entregaRech1(controlC->inspec_1->rechazado));
            emit(entregaRech2(controlC->inspec_2->rechazado));
            sleep(1);
        }
    }
}

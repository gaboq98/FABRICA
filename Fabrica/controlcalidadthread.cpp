#include "controlcalidadthread.h"


//DESCRIPCION: constructor del hilo  de control de calidad
ControlCalidadThread::ControlCalidadThread()
{
    encendido = true;
    detenerse = false;
}

//ENTRADAS: puntero de control de calidad
ControlCalidadThread::ControlCalidadThread(ControlCalidad* c)
{
    controlC = c;
    encendido = true;
    detenerse = false;
}


//DESCRIPCION: metodo run del hilo, cuando el hilo este encendido ejecuta la
//             funcion de control de calidad, emite los aprobados y rechazados
//             de los inspectores
void ControlCalidadThread::run()
{
    while (encendido) {
        if(detenerse) {
            sleep(0.5);
        } else {
            qDebug() << *controlC->banda;
            controlC->avanza();
            emit(entregaApr1(controlC->inspec_1->aprobado));
            emit(entregaApr2(controlC->inspec_2->aprobado));
            emit(entregaRech1(controlC->inspec_1->rechazado));
            emit(entregaRech2(controlC->inspec_2->rechazado));
            sleep(1);
        }
    }
}

#include "empacadorathread.h"

EmpacadoraThread::EmpacadoraThread()
{
    encendido = true;
    detenerse = false;
}

EmpacadoraThread::EmpacadoraThread(Empacadora* e)
{
    encendido = true;
    detenerse = false;
    empacadora = e;
}

void EmpacadoraThread::run()
{
    while (encendido) {
        if(detenerse) {
            sleep(0.5);
        } else {
            emit enviarPaquete(empacadora->empaca());
        }
    }
}
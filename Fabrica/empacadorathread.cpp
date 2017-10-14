#include "empacadorathread.h"

//DESCRIPCION: constructor deempacadora
EmpacadoraThread::EmpacadoraThread()
{
    encendido = true;
    detenerse = false;
}

//ENTRADAS: puntero a empacadora
//DESCRIPCION: constructor de control con
EmpacadoraThread::EmpacadoraThread(Empacadora* e)
{
    encendido = true;
    detenerse = false;
    empacadora = e;
}


//DESCRIPCION: metodo run del hilo, cuando el hilo este encendido
//             emite el valor de las cantidates totales y tipos de
//             cada tipo diferente de galleta
void EmpacadoraThread::run()
{
    while (encendido) {
        if(detenerse) {
            sleep(0.5);
        } else {
            empacadora->empaca();
            emit enviarPaquete(empacadora->totalpack, empacadora->lista);
            sleep(1);
        }
    }
}

void EmpacadoraThread::carritoMax(int)
{
}

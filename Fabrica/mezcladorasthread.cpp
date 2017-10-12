#include "mezcladorasthread.h"

MezcladorasThread::MezcladorasThread()
{
    encendido = true;
    detenerse = false;
}

MezcladorasThread::MezcladorasThread(MezcladoraMasa *m1)
{
    encendido = true;
    detenerse = false;
    mezcladora1 = m1;

}

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

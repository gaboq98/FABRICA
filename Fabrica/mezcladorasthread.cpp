#include "mezcladorasthread.h"

MezcladorasThread::MezcladorasThread()
{

}

void MezcladorasThread::run()
{
    while (encendido) {
        if(detenerse)
            sleep(0.5);
        else {
            //emit cambiarNumero(i++);
            sleep(1);
        }
    }
}

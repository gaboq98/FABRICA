#include "camionthread.h"

CamionThread::CamionThread()
{

}

CamionThread::CamionThread(Camion *c)
{
    encendido = true;
    detenerse = false;
    camion = c;

}

void CamionThread::run()
{
    while(encendido) {
        if(detenerse) {
            sleep(0.5);
        }
        if(camion->actual >= camion->maximo) {
            sleep(camion->tiempo);
            emit entregaGalletas(camion->entregar());
        }
        sleep(0.5);
    }
}

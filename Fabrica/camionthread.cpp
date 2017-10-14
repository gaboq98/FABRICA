#include "camionthread.h"


//DESCRIPCION: constructor del hilo de camion
CamionThread::CamionThread()
{

}

//ENTRADAS: puntero a camion
//DESCRIPCION: constructor que recibe un puntero a camion
CamionThread::CamionThread(Camion *c)
{
    encendido = true;
    detenerse = false;
    camion = c;

}


//DESCRIPCION: metodo run del hilo, cuando el hilo este encendido ejecuta la
//             funcion entregar del camion y la emite
void CamionThread::run()
{
    while(encendido) {
        if(detenerse) {
            sleep(0.5);
        }
        if(camion->actual >= camion->maximo) {
            sleep(camion->tiempo);
            emit entregaGalletas(camion->entregar());
            emit maxCamion(camion->actual);
        }
        sleep(0.5);
    }
}

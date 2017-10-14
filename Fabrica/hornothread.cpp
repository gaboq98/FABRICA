#include "hornothread.h"


//DESCRIPCION: constructor de hilo del horno
HornoThread::HornoThread()
{
    encendido = true;
    detenerse = false;
}


//DESCRIPCION: implementacion de la funcion run()
//             recorre los horno y los itera hasta
//             llenarlos y cumplir el tiempo de llenado
//             emite la cantidad actual delos hornos a la interfaz
//             emite la cantidad total de galletas horneadas
void HornoThread::run()
{
    while(encendido) {
        if(detenerse) {
            sleep(0.5);
        } else {
            for(int i = 0; i < 6; i++) {
                Horno *horno = hornos[i];
                horno->galletas = galletas;
                if(horno->encendido || *galletas > 0) {
                    if (horno->hornea()) {
                        galletasCocinadas += horno->maximo;
                        continue;
                    }
                    if(!horno->cocinando) {
                        break;
                    } else {
                        continue;
                    }
                } else {
                    continue;
                }             
            }
            emit cambiarHornos(horno1->actual, horno2->actual, horno3->actual, horno4->actual, horno5->actual, horno6->actual);
            emit totalGalletas(horno1->total, horno2->total, horno3->total, horno4->total, horno5->total, horno6->total);
            sleep(1);
        }
    }
}

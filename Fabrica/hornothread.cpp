#include "hornothread.h"

HornoThread::HornoThread()
{
    encendido = true;
    detenerse = false;
}

void HornoThread::run()
{
    while(encendido) {
        if(detenerse) {
            sleep(0.5);
        } else {
            for(int i = 0; i < 6; i++) {
                Horno *horno = hornos[i];
                horno->galletas = galletas;
                if(horno->encendido) {
                    if(*galletas > 0) {
                        if (horno->hornea()) {
                            galletasCocinadas += horno->maximo;
                            continue;
                        }
                    }
                } else {
                    continue;
                }
                emit cambiarHornos(horno1->actual, horno2->actual, horno3->actual, horno4->actual, horno5->actual, horno6->actual);
                emit totalGalletas(horno1->total, horno2->total, horno3->total, horno4->total, horno5->total, horno6->total);

            }
            sleep(1);
        }
    }
}

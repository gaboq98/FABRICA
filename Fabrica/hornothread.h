#ifndef HORNOTHREAD_H
#define HORNOTHREAD_H
#include <QtCore>
#include "horno.h"

class HornoThread : public QThread
{
    Q_OBJECT
public:
    HornoThread();
    void run();
    Horno *horno1 = new Horno();
    Horno *horno2 = new Horno();
    Horno *horno3 = new Horno();
    Horno *horno4 = new Horno();
    Horno *horno5 = new Horno();
    Horno *horno6 = new Horno();
    Horno *hornos[6] = {horno1, horno2, horno3, horno4, horno5, horno6};
    bool encendido;
    bool detenerse;
    int *galletas;
    int galletasCocinadas;

signals:
    void cambiarHornos(int, int, int, int, int, int);
    void totalGalletas(int, int, int, int, int, int);

};

#endif // HORNOTHREAD_H

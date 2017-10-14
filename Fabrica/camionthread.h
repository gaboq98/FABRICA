#ifndef CAMIONTHREAD_H
#define CAMIONTHREAD_H
#include <QtCore>
#include "camion.h"

class CamionThread : public QThread
{
    Q_OBJECT
public:
    CamionThread();
    CamionThread(Camion *c);
    Camion *camion;
    bool encendido;
    bool detenerse;
    void run();

signals:
    void entregaGalletas(int);

};

#endif // CAMIONTHREAD_H

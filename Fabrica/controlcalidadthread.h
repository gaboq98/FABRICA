#ifndef CONTROLCALIDADTHREAD_H
#define CONTROLCALIDADTHREAD_H
#include <QtCore>
#include <QObject>
#include "controlcalidad.h"

class ControlCalidadThread : public QThread
{
    Q_OBJECT

public:
    explicit ControlCalidadThread();
    ControlCalidadThread(ControlCalidad* c);
    void run();
    bool encendido;
    bool detenerse;
    ControlCalidad* controlC;

signals:
    void entregaApr1(int);
    void entregaApr2(int);
    void entregaRech1(int);
    void entregaRech2(int);

public slots:

};

#endif // CONTROLCALIDADTHREAD_H

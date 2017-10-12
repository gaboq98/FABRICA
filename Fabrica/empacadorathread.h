#ifndef EMPACADORATHREAD_H
#define EMPACADORATHREAD_H
#include <QtCore>
#include "QDebug"
#include "empacadora.h"

class EmpacadoraThread : public QThread
{
    Q_OBJECT

public:
    explicit EmpacadoraThread();
    EmpacadoraThread(Empacadora* e);
    void run();
    bool encendido;
    bool detenerse;
    Empacadora* empacadora;

signals:
    void enviarPaquete(int);

};

#endif // EMPACADORATHREAD_H

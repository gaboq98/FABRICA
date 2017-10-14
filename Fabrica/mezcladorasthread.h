#ifndef MEZCLADORASTHREAD_H
#define MEZCLADORASTHREAD_H
#include <QtCore>
#include "QDebug"
#include "mezcladoramasa.h"

class MezcladorasThread : public QThread
{
    Q_OBJECT

public:
    explicit MezcladorasThread();
    MezcladorasThread(MezcladoraMasa* m1);
    void run();
    bool encendido;
    bool detenerse;
    //
    MezcladoraMasa *mezcladora1;


signals:
    void recibeBanda();
    void entregarM1(int);
    void banda(int);


public slots:


};

#endif // MEZCLADORASTHREAD_H

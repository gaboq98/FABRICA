#ifndef MEZCLADORASTHREAD_H
#define MEZCLADORASTHREAD_H
#include <QtCore>
#include "mezcladoramasa.h"
#include "cola.h"

class MezcladorasThread : public QThread
{
    Q_OBJECT

public:
    explicit MezcladorasThread();
    void run();
    bool encendido;
    bool detenerse;
    //


signals:

    void entregar(int);

public slots:


};

#endif // MEZCLADORASTHREAD_H

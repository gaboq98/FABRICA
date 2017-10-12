#ifndef ENSAMBLADORATHREAD_H
#define ENSAMBLADORATHREAD_H
#include <QtCore>
#include <QObject>
#import "ensambladora.h"

class EnsambladoraThread : public QThread
{
    Q_OBJECT

public:
    EnsambladoraThread();
    EnsambladoraThread(Ensambladora* e);
    void run();
    bool encendido;
    bool detenerse;
    Ensambladora* ensambladora;


signals:
    void procesadoEnsambladora(int);

public slots:


};

#endif // ENSAMBLADORATHREAD_H

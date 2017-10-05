#include "mainthread.h"
#include <QtCore>
#include <QDebug>

MainThread::MainThread(QObject *parent) : QThread(parent)
{
    this->encendido = true;
    this->detenerse = false;
}

void MainThread::run()
{
    int i = 0;
    while (encendido) {
        if(detenerse)
            sleep(0.5);
        else {
            emit cambiarNumero(i++);
            qDebug() << i << "come penes";
            sleep(1);
        }
    }

}


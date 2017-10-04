#include "mainthread.h"
#include <QtCore>
#include <QDebug>

MainThread::MainThread(QObject *parent) : QThread(parent)
{

}

void MainThread::run()
{
    int i = 0;
    while (true) {
        if(detenerse)
            break;
        emit cambiarNumero(i++);
        qDebug() << this->nombre << "come penes";
        sleep(1);
    }

}


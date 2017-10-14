#include "mainthread.h"
#include <QtCore>
#include <QDebug>


//DESCRIPCION: constructor de hilo principal
MainThread::MainThread(QObject *parent) : QThread(parent)
{
    this->encendido = true;
    this->detenerse = false;
}

void MainThread::run()
{

}


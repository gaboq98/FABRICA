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

}


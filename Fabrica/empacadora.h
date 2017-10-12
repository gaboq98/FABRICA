#ifndef EMPACADORA_H
#define EMPACADORA_H
#include <QVector>


struct Empacadora
{
    int banda;
    QVector<int> tiposDePaquete;
    Empacadora();
    int empaca();
};

#endif // EMPACADORA_H

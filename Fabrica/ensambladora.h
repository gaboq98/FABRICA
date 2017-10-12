#ifndef ENSAMBLADORA_H
#define ENSAMBLADORA_H
#include "QDebug"

struct Ensambladora
{
public:
    Ensambladora();
    int *masa;
    int *chocolate;
    int mpg;    //masa por galleta
    int cpg;    //chocolate por galleta
    int gps;    //galletas por segundo
    bool encendido;
    int procesado;
    void procesa();


};

#endif // ENSAMBLADORA_H

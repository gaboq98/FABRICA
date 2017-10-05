#include "ensambladora.h"

Ensambladora::Ensambladora()
{
    cintaChocolate = cintaChocolate = 0;
    cantMasa = 2;
    cantChoco = 1;
    max = 5800;
}

Ensambladora::Ensambladora(int m, int cMasa,int cChoco){
    cantMasa = cMasa;
    cantChoco = cChoco;
    cintaChocolate = cintaChocolate = 0;
    max = m;
}

int Ensambladora::preparar(){
    cintaChocolate -= cantChoco;
    cintaMezcla -= cantMasa;
    return 1;
}

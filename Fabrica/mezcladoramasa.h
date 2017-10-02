#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H


struct Masa{
    float gramos;
    Masa() {}
    Masa(float gr){
        gramos = gr;
    }
};


struct MezcladoraMasa{
    int maximo;
    int minimo;
    int cantidad;
    int ups; // unidades por segundo
    MezcladoraMasa();
    MezcladoraMasa(int min, int max);
    void insertarMasa(int cant);
    Masa* procesa();
};

#endif // MEZCLADORAMASA_H

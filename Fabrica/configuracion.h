#ifndef CONFIGURACION_H
#define CONFIGURACION_H
#include <QDialog>
#include "mezcladorasthread.h"
#include "ensambladorathread.h"
#include "hornothread.h"
#include "controlcalidadthread.h"

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = 0);
    ~Configuracion();
    Ui::Configuracion *ui;

    Configuracion(MezcladoraMasa *m1, MezcladoraMasa *m2, MezcladoraMasa *m3, Ensambladora *e,
                  HornoThread *horno, ControlCalidad *c1);

    int *maxMezcladora1;
    int *minMezcladora1;
    int *upsMezcladora1;

    int *maxMezcladora2;
    int *minMezcladora2;
    int *upsMezcladora2;

    int *maxMezcladora3;
    int *minMezcladora3;
    int *upsMezcladora3;

    int *mspEnsambladora;
    int *cspEnsambladora;
    int *gspEnsambladora;

    int *maxHorno1;
    int *tiempoHorno1;

    int *maxHorno2;
    int *tiempoHorno2;

    int *maxHorno3;
    int *tiempoHorno3;

    int *maxHorno4;
    int *tiempoHorno4;

    int *maxHorno5;
    int *tiempoHorno5;

    int *maxHorno6;
    int *tiempoHorno6;

    int *porcentajeInspector1;

    int *porcentajeInspector2;

};

#endif // CONFIGURACION_H

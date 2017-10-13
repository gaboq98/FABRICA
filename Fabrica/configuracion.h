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

    MezcladoraMasa *mezcladora1;
    MezcladoraMasa *mezcladora2;
    MezcladoraMasa *mezcladora3;
    Ensambladora *ensambladora;
    HornoThread *horno;
    ControlCalidad *controlCalidad;

    void asignarValores(MezcladoraMasa *m1, MezcladoraMasa *m2, MezcladoraMasa *m3, Ensambladora *e,
                        HornoThread *horno, ControlCalidad *c1);

};

#endif // CONFIGURACION_H

#include "configuracion.h"
#include "ui_configuracion.h"

Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);

}

Configuracion::~Configuracion()
{
    delete ui;
}

Configuracion::Configuracion(MezcladoraMasa *m1, MezcladoraMasa *m2, MezcladoraMasa *m3, Ensambladora *e, HornoThread *horno, ControlCalidad *c1)
{
    m1->maximo = ui->max_mezcl1->value();
    m1->ups = ui->tiempo_mezcl1->value();

    m2->maximo = ui->max_mezcl2->value();
    m2->ups = ui->tiempo_mezcl2->value();

    m3->maximo = ui->max_mezcl3->value();
    m3->ups = ui->tiempo_mezcl3->value();

    e->gps = ui->galletas_ensam->value() / ui->tiempo_ensam->value();

    horno->horno1->maximo = ui->max_horno1->value();
    horno->horno1->tiempo = ui->tiempo_horno1->value();
    horno->horno2->maximo = ui->max_horno2->value();
    horno->horno2->tiempo = ui->tiempo_horno2->value();
    horno->horno3->maximo = ui->max_horno3->value();
    horno->horno3->tiempo = ui->tiempo_horno3->value();
    horno->horno4->maximo = ui->max_horno4->value();
    horno->horno4->tiempo = ui->tiempo_horno4->value();
    horno->horno5->maximo = ui->max_horno5->value();
    horno->horno5->tiempo = ui->tiempo_horno5->value();
    horno->horno6->maximo = ui->max_horno6->value();
    horno->horno6->tiempo = ui->tiempo_horno6->value();

    c1->inspec_1->porcentaje = ui->prob_inspec_1->value();
    c1->inspec_2->porcentaje = ui->prob_inspec_2->value();

}

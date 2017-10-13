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

void Configuracion::asignarValores(MezcladoraMasa *m1, MezcladoraMasa *m2, MezcladoraMasa *m3, Ensambladora *e, HornoThread *hornos, ControlCalidad *c1)
{
    mezcladora1 = m1;
    mezcladora2 = m2;
    mezcladora3 = m3;
    ensambladora = e;
    horno = hornos;
    controlCalidad = c1;

    mezcladora1->maximo = ui->max_mezcl1->value();
    mezcladora1->ups = ui->gramos_mezcl1->value() / ui->tiempo_mezcl1->value();
    mezcladora1->minimo = 10;
    mezcladora2->maximo = ui->max_mezcl2->value();
    mezcladora2->ups = ui->gramos_mezcl2->value() / ui->tiempo_mezcl2->value();
    mezcladora2->minimo = 10;
    mezcladora3->maximo = ui->max_mezcl3->value();
    mezcladora3->ups = ui->gramos_mezcl3->value() / ui->tiempo_mezcl3->value();
    mezcladora3->minimo = 10;

    ensambladora->gps = ui->galletas_ensam->value() / ui->tiempo_ensam->value();
    ensambladora->mpg = 8;
    ensambladora->cpg = 2;

    horno->horno1->maximo = ui->max_horno1->value();
    horno->horno2->maximo = ui->max_horno2->value();
    horno->horno3->maximo = ui->max_horno3->value();
    horno->horno4->maximo = ui->max_horno4->value();
    horno->horno5->maximo = ui->max_horno5->value();
    horno->horno6->maximo = ui->max_horno6->value();

    horno->horno1->tiempo = ui->tiempo_horno1->value();
    horno->horno2->tiempo = ui->tiempo_horno2->value();
    horno->horno3->tiempo = ui->tiempo_horno3->value();
    horno->horno4->tiempo = ui->tiempo_horno4->value();
    horno->horno5->tiempo = ui->tiempo_horno5->value();
    horno->horno6->tiempo = ui->tiempo_horno6->value();

    controlCalidad->inspec_1->porcentaje = ui->prob_inspec_1->value();
    controlCalidad->inspec_2->porcentaje = ui->prob_inspec_2->value();
    qDebug() << "Asignar valores";

    lista = new ListaCircular();

}

void Configuracion::on_pushButton_clicked()
{
    lista->insertar( ui->cantidad_por_paquete, ui->cantidad_de_paquetes);
    QString str = ui->cantidad_de_paquetes + " paquetes de " + ui->cantidad_por_paquete + "\n";
    ui->lista_de_paquetes->appendPlainText(str);
}


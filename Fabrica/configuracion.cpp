#include "configuracion.h"
#include "ui_configuracion.h"


//DESCRIPCION: contructor de configuracion
Configuracion::Configuracion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuracion)
{
    ui->setupUi(this);
    lista = new ListaCircular();

}

//DESCRIPCION: deconstructor de la clase configuracion
Configuracion::~Configuracion()
{
    delete ui;
}

//ENTRADAS: puntero a mezcladora 1, puntero a mezcladora 2, puntero a mezcladora chocolate
//          puntero a ensambladora de galletas, puntero a hornos,
//          puntero a cinta de control de calidad, puntero a empacadora
//
//DESCRIPCION: funcion asigna los parametros de las de las estructuras adignados en la configuracion
void Configuracion::asignarValores(MezcladoraMasa *m1, MezcladoraMasa *m2, MezcladoraMasa *m3, Ensambladora *e,
                                   HornoThread *hornos, ControlCalidad *c1, Empacadora *emp)
{
    mezcladora1 = m1;
    mezcladora2 = m2;
    mezcladora3 = m3;
    ensambladora = e;
    horno = hornos;
    controlCalidad = c1;
    empacadora = emp;

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

    empacadora->lista = lista;

}


//DESCRIPCION: funcion que agrega un elemento en la lista de galletas,
//             obtiene los valores de la configuracion y agrega el string a
//             area de texto, tambien, se setea el valor maximo de la probabilidad por paquete
void Configuracion::on_pushButton_clicked()
{
    Camion *camion = new Camion();
    CamionThread *thread = new CamionThread(camion);
    thread->start();
    camion->maximo = ui->max_camion_entrega->value();
    camion->tiempo = ui->tiempo_camion->value();
    lista->insertar(ui->cantidad_por_paquete->value(), ui->cantidad_de_paquetes->value(), camion);
    QString str = QString::number(ui->cantidad_de_paquetes->value()) + " paquetes de " + QString::number(ui->cantidad_por_paquete->value());
    ui->lista_de_paquetes->appendPlainText(str);
    ui->probabilidad_paquete->setMaximum(ui->probabilidad_paquete->maximum() - ui->probabilidad_paquete->value());
    if(ui->probabilidad_paquete->maximum() == 0)
        ui->pushButton->setEnabled(false);
}

//DESCRIPCION: funcion del boton guardar, cierra la ventana de configuracion
void Configuracion::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

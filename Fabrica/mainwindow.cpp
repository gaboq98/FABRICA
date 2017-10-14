#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


//DESCRIPCION: constructor de la ventana principal
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bandaMasa = 0;
    bandaChocolate = 0;

    mezcladora1 = new MezcladoraMasa();
    mezcladora2 = new MezcladoraMasa();
    mezcladora3 = new MezcladoraMasa();

    mezcladoraThread1 = new MezcladorasThread(mezcladora1);
    mezcladoraThread2 = new MezcladorasThread(mezcladora2);
    mezcladoraThread3 = new MezcladorasThread(mezcladora3);

    connect(mezcladoraThread1, SIGNAL(entregarM1(int)), this, SLOT(cambiandoMezcladora1(int)));
    connect(mezcladoraThread2, SIGNAL(entregarM1(int)), this, SLOT(cambiandoMezcladora2(int)));
    connect(mezcladoraThread3, SIGNAL(entregarM1(int)), this, SLOT(cambiandoMezcladora3(int)));

    connect(mezcladoraThread1, SIGNAL(banda(int)), this, SLOT(cambiarBanda1(int)));
    connect(mezcladoraThread2, SIGNAL(banda(int)), this, SLOT(cambiarBanda12(int)));
    connect(mezcladoraThread3, SIGNAL(banda(int)), this, SLOT(cambiarBanda2(int)));

    connect(mezcladoraThread1, SIGNAL(recibeBanda()), this, SLOT(ponerBanda()));
    connect(mezcladoraThread2, SIGNAL(recibeBanda()), this, SLOT(ponerBanda()));

    ensambladora = new Ensambladora();

    ensambladoraThread = new EnsambladoraThread(ensambladora);
    ensambladora->masa = &bandaMasa;
    ensambladora->chocolate = &bandaChocolate;

    bandaHorno = -1;

    connect(ensambladoraThread, SIGNAL(procesadoEnsambladora(int)), this, SLOT(cambiarBandaHorno(int)));

    hornoThread = new HornoThread();
    hornoThread->galletas = &bandaHorno;

    connect(hornoThread, SIGNAL(cambiarHornos(int,int,int,int,int,int)), this, SLOT(hornosActual(int,int,int,int,int,int)));
    connect(hornoThread, SIGNAL(totalGalletas(int,int,int,int,int,int)), this, SLOT(hornosTotal(int,int,int,int,int,int)));

    controlCalidad = new ControlCalidad();
    controlCalidad->banda = &hornoThread->galletasCocinadas;

    controlThread = new ControlCalidadThread(controlCalidad);

    connect(controlThread, SIGNAL( entregaApr1(int)), this, SLOT(cambiarAprobado1(int)));
    connect(controlThread, SIGNAL( entregaApr2(int)), this, SLOT(cambiarAprobado2(int)));
    connect(controlThread, SIGNAL( entregaRech1(int)), this, SLOT(cambiarRechazado1(int)));
    connect(controlThread, SIGNAL( entregaRech2(int)), this, SLOT(cambiarRechazado2(int)));

    empacadora = new Empacadora;
    empacadora->banda = &controlCalidad->salida;

    empacadoraThread = new EmpacadoraThread(empacadora);

    connect(empacadoraThread, SIGNAL(enviarPaquete(QVector<int>,ListaCircular*)), this, SLOT(recibirPaquete(QVector<int>,ListaCircular*)));

    config = new Configuracion(this);
    config->asignarValores(mezcladora1, mezcladora2, mezcladora3, ensambladora, hornoThread, controlCalidad, empacadora);

    empacadora->set_lista(config->lista);

}


//DESCRIPCION: deconstructor de la clase
MainWindow::~MainWindow()
{
    mezcladoraThread1->encendido = false;
    mezcladoraThread1->wait();
    mezcladoraThread2->encendido = false;
    mezcladoraThread2->wait();
    mezcladoraThread3->encendido = false;
    mezcladoraThread3->wait();
    ensambladoraThread->encendido = false;
    ensambladoraThread->wait();
    hornoThread->encendido = false;
    hornoThread->wait();
    empacadoraThread->encendido = false;
    empacadoraThread->wait();
    delete ui;
}


//ENTRADAS: numero entero
//DESCRIPCION:cambia el valor de los gramos procesados
//SALIDA: void
void MainWindow::cambiandoMezcladora1(int num)
{
    ui->mezcladora1->setValue(num);
}

//ENTRADAS: numero entero
//DESCRIPCION:cambia el valor de los gramos procesados
//SALIDA: void
void MainWindow::cambiandoMezcladora2(int num)
{
    ui->mezcladora2->setValue(num);
}

//ENTRADAS:numero entero
//DESCRIPCION: cambia el valor de los gramos procesados
//SALIDA:void
void MainWindow::cambiandoMezcladora3(int num)
{
    ui->mezcladora3->setValue(num);
}

//ENTRADAS: numero entero
//DESCRIPCION: suma el valor de masa o  numero de paquetes
//SALIDA: void
void MainWindow::cambiarBanda1(int num)
{
    bandaMasa += num;
}

//ENTRADAS:numero entero
//DESCRIPCION: cambia el valor de la cinta de
//SALIDA:void
void MainWindow::cambiarBanda12(int num)
{
    bandaMasa += num;
}

//ENTRADAS: numero entero
//DESCRIPCION: suma el valor de masa o  numero de paquetes
//SALIDA: void
void MainWindow::cambiarBanda2(int num)
{
    bandaChocolate += num;
}

//ENTRADAS: numero entero
//DESCRIPCION: asigna el valor a representar en pantalla en la banda galletas
//SALIDA: void
void MainWindow::cambiarBandaHorno(int num)
{
    bandaHorno += num;
    ui->cintaHorno->setValue(bandaHorno);
    ui->ensambladora->setValue(ensambladora->procesado);
}

//ENTRADAS:
//DESCRIPCION: asigna el valor de las bandas de mezclar
//SALIDA: void
void MainWindow::ponerBanda()
{
    ui->cintaMezcla->setValue(bandaMasa);
    ui->cintaChoco->setValue(bandaChocolate);
}

//ENTRADAS: numero entero
//DESCRIPCION: cambia el numero de galletas aprobadas en pantalla
//SALIDA: void
void MainWindow::cambiarAprobado1(int num)
{
    ui->calida1_aprovados->setValue(num);
}

//ENTRADAS: numero entero
//DESCRIPCION: cambia el numero de galletas aprobadas en pantalla
//SALIDA: void
void MainWindow::cambiarAprobado2(int num)
{
    ui->calida2_aprovados->setValue(num);
}

//ENTRADAS: numero entero
//DESCRIPCION: cambia el numero de galletas rechazadas en pantalla
//SALIDA: void
void MainWindow::cambiarRechazado1(int num)
{
    ui->calida1_desechados->setValue(num);
}

//ENTRADAS: numero entero
//DESCRIPCION: cambia el numero de galletas rechazadas en pantalla
//SALIDA: void
void MainWindow::cambiarRechazado2(int num)
{
    ui->calida2_desechados->setValue(num);
}

//ENTRADAS: actual de (horno1, horno2, horno3, horno4, horno4, horno5, horno 6)
//DESCRIPCION: asigna el valor de los actuales de cada horno
//SALIDA: void
void MainWindow::hornosActual(int h1, int h2, int h3, int h4, int h5, int h6)
{
    ui->horno_1->setValue(h1);
    ui->horno_2->setValue(h2);
    ui->horno_3->setValue(h3);
    ui->horno_4->setValue(h4);
    ui->horno_5->setValue(h5);
    ui->horno_6->setValue(h6);
}


//ENTRADAS: total de (horno1, horno2, horno3, horno4, horno4, horno5, horno 6)
//DESCRIPCION: asigna el valor de los total de cada horno
//SALIDA: void
void MainWindow::hornosTotal(int h1, int h2, int h3, int h4, int h5, int h6)
{
    ui->horno1_total->setValue(h1);
    ui->horno2_total->setValue(h2);
    ui->horno3_total->setValue(h3);
    ui->horno4_total->setValue(h4);
    ui->horno5_total->setValue(h5);
    ui->horno6_total->setValue(h6);
}

//ENTRADAS: array de total de empacados, listacircular
//DESCRIPCION: recibe array con la cantodad total de galletas y la imprime en pantalla
//SALIDA: void
void MainWindow::recibirPaquete(QVector<int> vector, ListaCircular *lista)
{
    qDebug() << "pee";
    for(int i = 0; i < vector.size(); i++) {
        ui->empacador->appendPlainText(QString(QString::number(i) + " por paquete de " + QString::number(lista->obtener(i)->paquete)));
    }
}

//ENTRADAS:
//DESCRIPCION: enciende todas las maquinas
//SALIDA: void
void MainWindow::on_btnInicio_clicked()
{
    mezcladoraThread1->start();
    mezcladoraThread1->detenerse = false;

    mezcladoraThread2->start();
    mezcladoraThread2->detenerse = false;

    mezcladoraThread3->start();
    mezcladoraThread3->detenerse = false;

    ensambladoraThread->start();
    ensambladoraThread->detenerse = false;

    hornoThread->start();
    hornoThread->detenerse = false;

    controlThread->start();
    controlThread->detenerse = false;

    empacadoraThread->start();
    empacadoraThread->detenerse = false;

}

//ENTRADAS:
//DESCRIPCION: pone en pausa las maquinas y personas
//SALIDA: void
void MainWindow::on_btnPausa_clicked()
{
    mezcladoraThread1->detenerse = true;
    mezcladoraThread2->detenerse = true;
    mezcladoraThread3->detenerse = true;
    ensambladoraThread->detenerse = true;
    hornoThread->detenerse = true;
    controlThread->detenerse = true;
    empacadoraThread->detenerse = true;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnMezcladora1_clicked()
{
    mezcladoraThread1->detenerse = !mezcladoraThread1->detenerse;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnMezcladora2_clicked()
{
    mezcladoraThread2->detenerse = !mezcladoraThread2->detenerse;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnMezcladora3_clicked()
{
    mezcladoraThread3->detenerse = !mezcladoraThread3->detenerse;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnEnsambladora_clicked()
{
    ensambladoraThread->detenerse = !ensambladoraThread->detenerse;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnHorno1_clicked()
{
    hornoThread->horno1->encendido = !hornoThread->horno1->encendido;
}


//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnHorno_2_clicked()
{
    hornoThread->horno4->encendido = !hornoThread->horno4->encendido;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnHorno_3_clicked()
{
    hornoThread->horno3->encendido = !hornoThread->horno3->encendido;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnHorno_4_clicked()
{
    hornoThread->horno6->encendido = !hornoThread->horno6->encendido;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnCalidad1_clicked()
{
    controlCalidad->inspec_1->detenerse = !controlCalidad->inspec_1->detenerse;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnCalidad2_clicked()
{
    controlCalidad->inspec_2->detenerse = !controlCalidad->inspec_2->detenerse;
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btn_config_clicked()
{
    config->setVisible(true);
}

//ENTRADAS:
//DESCRIPCION: cambia el estado de la maquina,
//             si estaba en pausa la pone a trabajr y viceversa
//SALIDA: void
void MainWindow::on_btnEmpacadora_clicked()
{
    empacadoraThread->detenerse = !empacadoraThread->detenerse;
}

void MainWindow::on_btnReiniciar_clicked()
{
    on_btnPausa_clicked();
    MainWindow();
    cambiandoMezcladora1(0);
    cambiandoMezcladora2(0);
    cambiandoMezcladora3(0);
    cambiarBanda1(0);
    cambiarBanda2(0);
    bandaMasa = 0;
    bandaChocolate = 0;
    bandaHorno = 0;
    ensambladora->procesado = 0;
    ponerBanda();
    hornosActual(0,0,0,0,0,0);
    hornosTotal(0,0,0,0,0,0);
    cambiarAprobado1(0);
    cambiarAprobado2(0);
    cambiarBandaHorno(0);
    cambiarRechazado1(0);
    cambiarRechazado2(0);
}

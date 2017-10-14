#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

    empacadora = new Empacadora();
    empacadora->banda = &controlCalidad->salida;

    empacadoraThread = new EmpacadoraThread(empacadora);

    config = new Configuracion(this);
    connect(config, SIGNAL(actualizarLista(ListaCircular*)), this, SLOT(recibeLista(ListaCircular*)));
    connect(empacadoraThread, SIGNAL(enviarPaquete(QVector<int>,ListaCircular*)), this, SLOT(recibirPaquete(QVector<int>,ListaCircular*)));

}

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

void MainWindow::cambiandoMezcladora1(int num)
{
    ui->mezcladora1->setValue(num);
}

void MainWindow::cambiandoMezcladora2(int num)
{
    ui->mezcladora2->setValue(num);
}

void MainWindow::cambiandoMezcladora3(int num)
{
    ui->mezcladora3->setValue(num);
}

void MainWindow::cambiarBanda1(int num)
{
    bandaMasa += num;
}

void MainWindow::cambiarBanda12(int num)
{
    bandaMasa += num;
}

void MainWindow::cambiarBanda2(int num)
{
    bandaChocolate += num;
}

void MainWindow::cambiarBandaHorno(int num)
{
    bandaHorno += num;
    ui->cintaHorno->setValue(bandaHorno);
    ui->ensambladora->setValue(ensambladora->procesado);
}

void MainWindow::ponerBanda()
{
    ui->cintaMezcla->setValue(bandaMasa);
    ui->cintaChoco->setValue(bandaChocolate);
}

void MainWindow::cambiarAprobado1(int num)
{
    ui->calida1_aprovados->setValue(num);
}

void MainWindow::cambiarAprobado2(int num)
{
    ui->calida2_aprovados->setValue(num);
}

void MainWindow::cambiarRechazado1(int num)
{
    ui->calida1_desechados->setValue(num);
}

void MainWindow::cambiarRechazado2(int num)
{
    ui->calida2_desechados->setValue(num);
}

void MainWindow::hornosActual(int h1, int h2, int h3, int h4, int h5, int h6)
{
    ui->horno_1->setValue(h1);
    ui->horno_2->setValue(h2);
    ui->horno_3->setValue(h3);
    ui->horno_4->setValue(h4);
    ui->horno_5->setValue(h5);
    ui->horno_6->setValue(h6);
}

void MainWindow::hornosTotal(int h1, int h2, int h3, int h4, int h5, int h6)
{
    ui->horno1_total->setValue(h1);
    ui->horno2_total->setValue(h2);
    ui->horno3_total->setValue(h3);
    ui->horno4_total->setValue(h4);
    ui->horno5_total->setValue(h5);
    ui->horno6_total->setValue(h6);
}

void MainWindow::recibirPaquete(QVector<int> vector, ListaCircular *lista)
{
    ui->empacador->document()->setPlainText("");
    for(int i = 0; i < vector.size(); i++) {
        ui->empacador->appendPlainText(QString(QString::number(vector[i]) + " paquetes de " + QString::number(lista->obtener(i)->paquete) + " galletas"));
    }
}

void MainWindow::recibeLista(ListaCircular*l)
{
    empacadora->set_lista(l);
}

void MainWindow::on_btnInicio_clicked()
{
    config->asignarValores(mezcladora1, mezcladora2, mezcladora3, ensambladora, hornoThread, controlCalidad, empacadora);
    //empacadora->set_lista(config->lista);
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

void MainWindow::on_btnMezcladora1_clicked()
{
    mezcladoraThread1->detenerse = !mezcladoraThread1->detenerse;
}

void MainWindow::on_btnMezcladora2_clicked()
{
    mezcladoraThread2->detenerse = !mezcladoraThread2->detenerse;
}

void MainWindow::on_btnMezcladora3_clicked()
{
    mezcladoraThread3->detenerse = !mezcladoraThread3->detenerse;
}

void MainWindow::on_btnEnsambladora_clicked()
{
    ensambladoraThread->detenerse = !ensambladoraThread->detenerse;
}

void MainWindow::on_btnHorno1_clicked()
{
    hornoThread->horno1->encendido = !hornoThread->horno1->encendido;
}

void MainWindow::on_btnHorno_2_clicked()
{
    hornoThread->horno4->encendido = !hornoThread->horno4->encendido;
}

void MainWindow::on_btnHorno_3_clicked()
{
    hornoThread->horno3->encendido = !hornoThread->horno3->encendido;
}

void MainWindow::on_btnHorno_4_clicked()
{
    hornoThread->horno6->encendido = !hornoThread->horno6->encendido;
}

void MainWindow::on_btnCalidad1_clicked()
{
    controlCalidad->inspec_1->detenerse = !controlCalidad->inspec_1->detenerse;
}

void MainWindow::on_btnCalidad2_clicked()
{
    controlCalidad->inspec_2->detenerse = !controlCalidad->inspec_2->detenerse;
}

void MainWindow::on_btn_config_clicked()
{
    ui->btnPausa->click();
    config->setVisible(true);
}

void MainWindow::on_btnEmpacadora_clicked()
{
    empacadoraThread->detenerse = !empacadoraThread->detenerse;
}

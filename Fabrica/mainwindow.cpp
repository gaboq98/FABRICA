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

    mezcladora1->maximo = 1000;
    mezcladora1->minimo = 30;
    mezcladora1->ups = 10;
    mezcladora1->maquina = 1;

    mezcladora2->maximo = 400;
    mezcladora2->minimo = 20;
    mezcladora2->ups = 5;
    mezcladora2->maquina = 2;

    mezcladora3->maximo = 500;
    mezcladora3->minimo = 10;
    mezcladora3->ups = 5;
    mezcladora3->maquina = 3;

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

    ensambladora->mpg = 14;
    ensambladora->cpg = 4;
    ensambladora->gps = 1;

    ensambladoraThread = new EnsambladoraThread(ensambladora);
    ensambladora->masa = &bandaMasa;
    ensambladora->chocolate = &bandaChocolate;

    connect(ensambladoraThread, SIGNAL(procesadoEnsambladora(int)), this, SLOT(cambiarBandaHorno(int)));


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
    ui->cintaHorno->setValue(num);
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
}

void MainWindow::on_btnPausa_clicked()
{
    mezcladoraThread1->detenerse = true;
    mezcladoraThread2->detenerse = true;
    mezcladoraThread3->detenerse = true;
    ensambladoraThread->detenerse = true;
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

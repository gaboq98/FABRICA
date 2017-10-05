#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread1 = new MainThread(this);
    connect(thread1, SIGNAL(cambiarNumero(int)), this, SLOT(cambiandoMezcladora1(int)));

}

MainWindow::~MainWindow()
{
    thread1->encendido = false;
    thread1->wait();
    delete ui;
}

void MainWindow::cambiandoMezcladora1(int num)
{
    ui->mezcladora1->setValue(num);
}

void MainWindow::on_btnInicio_clicked()
{
    thread1->start();
    thread1->detenerse = false;
    qDebug() << "Boton inicio";
}

void MainWindow::on_btnPausa_clicked()
{
    thread1->detenerse = true;
    qDebug() << "Boton pausa";
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    thread1 = new MainThread(this);
    connect(thread1, SIGNAL(cambiarNumero(int)), this, SLOT(cambiandoNumero(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cambiandoNumero(int num)
{
    ui->mezcladora1->setValue(num);
}

void MainWindow::on_btnInicio_clicked()
{
    thread1->start();
}

void MainWindow::on_btnPausa_clicked()
{
    thread1->detenerse = true;
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "mezcladorasthread.h"
#include "ensambladorathread.h"
#include "hornothread.h"
#include "controlcalidadthread.h"
#include "configuracion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Configuracion *config;
    int bandaMasa;
    int bandaChocolate;
    int bandaHorno;
    MezcladoraMasa *mezcladora1;
    MezcladoraMasa *mezcladora2;
    MezcladoraMasa *mezcladora3;
    MezcladorasThread *mezcladoraThread1;
    MezcladorasThread *mezcladoraThread2;
    MezcladorasThread *mezcladoraThread3;
    Ensambladora *ensambladora;
    EnsambladoraThread *ensambladoraThread;
    HornoThread *hornoThread;
    ControlCalidad *controlCalidad;
    ControlCalidadThread *controlThread;


public slots:
    void cambiandoMezcladora1(int);
    void cambiandoMezcladora2(int);
    void cambiandoMezcladora3(int);
    void cambiarBanda1(int);
    void cambiarBanda12(int);
    void cambiarBanda2(int);
    void cambiarBandaHorno(int);
    void ponerBanda();
    void cambiarAprobado1(int);
    void cambiarAprobado2(int);
    void cambiarRechazado1(int);
    void cambiarRechazado2(int);
    void hornosActual(int, int, int, int, int, int);
    void hornosTotal(int, int, int, int, int, int);


private slots:
    void on_btnInicio_clicked();
    void on_btnPausa_clicked();
    void on_btnMezcladora1_clicked();
    void on_btnMezcladora2_clicked();
    void on_btnMezcladora3_clicked();
    void on_btnEnsambladora_clicked();
    void on_btnHorno1_clicked();
    void on_btnHorno_2_clicked();
    void on_btnHorno_3_clicked();
    void on_btnHorno_4_clicked();

    void on_btnCalidad1_clicked();

    void on_btnCalidad2_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

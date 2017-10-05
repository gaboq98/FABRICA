#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainthread.h"
#include "mezcladorasthread.h"
#include "camion.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Camion *camionMezcladoras = new Camion();
    MezcladoraMasa *mezcladora1 = new MezcladoraMasa(camionMezcladoras, 1);
    MezcladoraMasa *mezcladora2 = new MezcladoraMasa(camionMezcladoras, 2);
    MezcladoraMasa *mezcladora3 = new MezcladoraMasa(camionMezcladoras, 3);
    MezcladorasThread *mezcladorasThread;



public slots:
    void cambiandoMezcladora1(int);
    void cambiandoMezcladora2(int);
    void cambiandoMezcladora3(int);


private slots:
    void on_btnInicio_clicked();
    void on_btnPausa_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

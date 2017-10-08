#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "mezcladorasthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    MezcladoraMasa *mezcladora1;
    MezcladoraMasa *mezcladora2;
    MezcladoraMasa *mezcladora3;
    MezcladorasThread *mezcladoraThread1;
    MezcladorasThread *mezcladoraThread2;
    MezcladorasThread *mezcladoraThread3;


public slots:
    void cambiandoMezcladora1(int);
    void cambiandoMezcladora2(int);
    void cambiandoMezcladora3(int);
    void cambiarBanda1(int);
    void cambiarBanda2(int);


private slots:
    void on_btnInicio_clicked();
    void on_btnPausa_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

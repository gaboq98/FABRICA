#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mainthread.h"
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
    MainThread *thread1;


public slots:
    void cambiandoMezcladora1(int);


private slots:
    void on_btnInicio_clicked();
    void on_btnPausa_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

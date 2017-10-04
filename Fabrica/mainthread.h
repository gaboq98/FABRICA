#ifndef MAINTHREAD_H
#define MAINTHREAD_H
#include <QtCore>

class MainThread : public QThread
{
    Q_OBJECT
public:
    explicit MainThread(QObject *parent = 0);
    void run();
    QString nombre;
    bool detenerse;

signals:

    void cambiarNumero(int);

public slots:

};

#endif // MAINTHREAD_H

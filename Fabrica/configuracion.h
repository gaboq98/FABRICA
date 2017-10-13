#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <QDialog>

namespace Ui {
class Configuracion;
}

class Configuracion : public QDialog
{
    Q_OBJECT

public:
    explicit Configuracion(QWidget *parent = 0);
    ~Configuracion();

    Ui::Configuracion *ui;
};

#endif // CONFIGURACION_H

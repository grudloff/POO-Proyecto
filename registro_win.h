#ifndef REGISTRO_WIN_H
#define REGISTRO_WIN_H

#include <QDialog>
#include "registro.h"

namespace Ui {
class registro_win;
}

class registro_win : public QDialog
{
    Q_OBJECT

public:
    explicit registro_win(QWidget *parent = nullptr);
    registro_win(QWidget*,registro*);
    ~registro_win();

private slots:
    void on_cancelar_boton_clicked();

    void on_agregar_boton_clicked();

private:
    Ui::registro_win *ui;
    registro* reg;
};

#endif // REGISTRO_WIN_H

#ifndef BUSCAR_WIN_H
#define BUSCAR_WIN_H

#include <QDialog>
#include "registro.h"

namespace Ui {
class Buscar_win;
}

class Buscar_win : public QDialog
{
    Q_OBJECT

public:
    explicit Buscar_win(QWidget *parent = nullptr);
    Buscar_win(QWidget*,registro*);
    ~Buscar_win();
    registro* reg;

private slots:
    void on_volver_b_clicked();

    void on_buscar_button_clicked();

private:
    Ui::Buscar_win *ui;

};

#endif // BUSCAR_WIN_H

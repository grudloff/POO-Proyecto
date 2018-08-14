#include "buscar_win.h"
#include "ui_buscar_win.h"

Buscar_win::Buscar_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buscar_win)
{
    ui->setupUi(this);
}

Buscar_win::~Buscar_win()
{
    delete ui;
}

void Buscar_win::on_volver_b_clicked()
{
    close();
}

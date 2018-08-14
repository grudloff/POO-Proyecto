#include "registro_win.h"
#include "ui_registro_win.h"

registro_win::registro_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registro_win)
{
    ui->setupUi(this);
}

registro_win::~registro_win()
{
    delete ui;
}

void registro_win::on_cancelar_boton_clicked()
{
    close();
}

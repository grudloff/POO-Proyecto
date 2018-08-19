#include "registro_win.h"
#include "ui_registro_win.h"
#include "registro.h"

registro_win::registro_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registro_win)
{
    ui->setupUi(this);
}

registro_win::registro_win(QWidget *parent, registro* reg) :
    QDialog(parent),
    ui(new Ui::registro_win)
{
    ui->setupUi(this);
    this->reg=reg;
}

QLineEdit* registro_win::getPatente(){
    return ui->input_patente;
}

QLineEdit* registro_win::getNombre(){
    return ui->input_nombre;
}

QLineEdit* registro_win::getCargo(){
    return ui->input_cargo;
}



registro_win::~registro_win()
{
    delete ui;
}

void registro_win::on_cancelar_boton_clicked()
{
    if(ui->input_patente->text()==reg->getLast()->getPatente()){
        reg->pop();
    }
    close();
}

void registro_win::on_agregar_boton_clicked()
{
    QString patente, nombre, cargo;
    patente=ui->input_patente->text();
    nombre=ui->input_nombre->text();
    cargo=ui->input_cargo->text();


    reg->agregar(patente,nombre,cargo);
    close();




}

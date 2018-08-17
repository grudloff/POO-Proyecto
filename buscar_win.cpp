#include "buscar_win.h"
#include "ui_buscar_win.h"

Buscar_win::Buscar_win(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buscar_win)
{
    ui->setupUi(this);
}

Buscar_win::Buscar_win(QWidget *parent,registro* reg) :
    QDialog(parent),
    ui(new Ui::Buscar_win)
{
    ui->setupUi(this);
    this->reg=reg;
}

Buscar_win::~Buscar_win()
{
    delete ui;
}

void Buscar_win::on_volver_b_clicked()
{
    close();
}

void Buscar_win::on_buscar_button_clicked()
{
    car* cars;
    QString qstr;
    if(ui->opcion_p->isChecked()){
        QString patente=ui->input->text();
        cars=reg->buscarPorPatente(patente);
        if (cars==nullptr){
            qstr="No existe";

        }
        else{
            qstr="Patente: "+patente+ "\nNombre: "+cars->getNombre()+"\nCargo: "+cars->getCargo();

        }

    }
    else if(ui->opcion_n->isChecked()){
        QString nombre=ui->input->text();
        cars=reg->buscarPorNombre(nombre);
        if (cars==nullptr){
            qstr="No existe";

        }
        else{
            qstr="Patente: "+cars->getPatente()+ "\nNombre: "+cars->getNombre()+"\nCargo: "+cars->getCargo();

        }
    }
    else {
        qstr="Selecione criterio de busqueda";

    }
    ui->info_b->setText(qstr);
}


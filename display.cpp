#include "display.h"
#include "ui_display.h"
#include "registro_win.h"
#include "buscar_win.h"
Display::Display(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Display)
{
    ui->setupUi(this);
}

Display::~Display()
{
    delete ui;
}

void Display::on_reg_bot_clicked()
{
    registro_win registro_window;
    registro_window.setModal(true);
    registro_window.exec();
}

void Display::on_buscar_bot_clicked()
{
    Buscar_win buscar_window;
    buscar_window.setModal(true);
    buscar_window.exec();
}

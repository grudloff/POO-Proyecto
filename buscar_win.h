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
    /**
     * @brief Constructor por defecto de una ventana QDialog
     * @param parent: Puntero a la ventana desde donde se llama, o nulo en caso de omision.
     */
    explicit Buscar_win(QWidget *parent = nullptr);
    /**
     * @brief Constructor que toma con entrada puntero a registro para acceder a sus metodos.
     * @param parent: Puntero a la ventana desde donde se llama.
     * @param reg: Puntero al registro.
     */
    Buscar_win(QWidget*,registro*);
    ~Buscar_win();


private slots:
    /**
     * @brief Al apretar el boton volver se cierra la ventana de busqueda.
     */
    void on_volver_b_clicked();

    /**
     * @brief Al apretar buscar se busca el car segun el criterio seleccionado
     * y se muestra el resultado.
     */
    void on_buscar_button_clicked();

private:
    /**
     * @brief ui
     */
    Ui::Buscar_win *ui;
    /**
     * @brief Puntero a registro para efectuar las respectivas busquedas en la base de datos.
     */
    registro* reg;


};

#endif // BUSCAR_WIN_H

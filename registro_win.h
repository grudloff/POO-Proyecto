#ifndef REGISTRO_WIN_H
#define REGISTRO_WIN_H

#include <QDialog>
#include <QLineEdit>
#include "registro.h"

namespace Ui {
class registro_win;
}

class registro_win : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor por defecto de una ventana QDialog
     * @param parent: Puntero a la ventana desde donde se llama, o nulo en caso de omision.
     */
    explicit registro_win(QWidget *parent = nullptr);
    /**
     * @brief Constructor que toma con entrada puntero a registro para acceder a sus metodos.
     * @param parent: Puntero a la ventana desde donde se llama.
     * @param reg: Puntero al registro.
     */
    registro_win(QWidget*,registro*);
    ~registro_win();
    /**
     * @brief Da acceso a el cuadro de texto para obtener la patente
     * @return Puntero al cuadro de texto
     */
    QLineEdit* getPatente();
    /**
     * @brief Da acceso a el cuadro de texto para obtener el nombre
     * @return Puntero al cuadro de texto
     */
    QLineEdit* getNombre();
    /**
     * @brief Da acceso a el cuadro de texto para obtener el cargo
     * @return Puntero al cuadro de texto
     */
    QLineEdit* getCargo();

private slots:
    /**
     * @brief Al apretar el boton de cancelar se cierra la ventana
     * de registro, en caso de que esta se abrio para registrar una
     * nueva patente detectada esta la quita del vector entradas del
     * registro.
     */
    void on_cancelar_boton_clicked();
    /**
     * @brief Al apretar el boton de agregar se agrega un car con los
     * datos colocados en los cuadros de texto.
     */
    void on_agregar_boton_clicked();

private:
    /**
     * @brief ui
     */
    Ui::registro_win *ui;
    /**
     * @brief Con esto se accede a la información registrada en el vector entradas
     * junto a los metodos para su manejo.
     */
    registro* reg;
};

#endif // REGISTRO_WIN_H

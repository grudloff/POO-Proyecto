#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include "alpr.h"
#include "registro.h"
#include "registro_win.h"
#include "buscar_win.h"



namespace Ui {
class Display;
}


class Display : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor, en este se inicializa openALPR con su configuración,
     *  junto al registro de patentes y además se inicia el timer.
     * @param parent: puntero a la ventana que lo llama, en caso contrario es nulo.
     */
    explicit Display(QWidget *parent = nullptr);
    ~Display();

private slots:
    /**
     * @brief Al apretar el boton de registro se abre la ventana de registro.
     */
    void on_reg_bot_clicked();
    /**
     * @brief Al apretar el boton de buscar se abre la ventana de busqueda
     */

    void on_buscar_bot_clicked();
    /**
     * @brief Esto se ejecuta periodicamente gracias al timer.
     */
    void update();

private:
    /**
     * @brief last_patente: ultima patente detectada, para no repetir erroneamente una misma.
     */
    QString last_patente;
    /**
     * @brief ui
     */
    Ui::Display *ui;
    /**
     * @brief openalpr: Con este se configura para detectar patentes.
     */
    alpr::Alpr *openalpr;
    /**
     * @brief resultados: En este se guardan las patentes detectadas de cierta imagen.
     */
    alpr::AlprResults results;
    /**
     * @brief reg: Este contiene el vector entradas de los car registrados además de los metodos
     * para interactuar con este.
     */
    registro* reg;
};

#endif // DISPLAY_H

#ifndef REGISTRO_WIN_H
#define REGISTRO_WIN_H

#include <QDialog>

namespace Ui {
class registro_win;
}

class registro_win : public QDialog
{
    Q_OBJECT

public:
    explicit registro_win(QWidget *parent = nullptr);
    ~registro_win();

private slots:
    void on_cancelar_boton_clicked();

private:
    Ui::registro_win *ui;
};

#endif // REGISTRO_WIN_H

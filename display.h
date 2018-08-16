#ifndef DISPLAY_H
#define DISPLAY_H

#include <QMainWindow>
#include "alpr.h"

namespace Ui {
class Display;
}


class Display : public QMainWindow
{
    Q_OBJECT

public:
    explicit Display(QWidget *parent = nullptr);
    ~Display();

private slots:
    void on_reg_bot_clicked();

    void on_buscar_bot_clicked();

    void update();

private:
    Ui::Display *ui;
    alpr::Alpr *openalpr;
    alpr::AlprResults results;
};

#endif // DISPLAY_H

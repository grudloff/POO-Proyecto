#ifndef REGISTRO_H
#define REGISTRO_H

#include <QString>
#include "stdlib.h"
using namespace std;
#include "car.h"

class registro
{
public:
    registro();
    registro(QString);
    void agregar(QString,QString,QString);
    void setLastPatente(QString);
    void setLastCargo(QString);
    void setLastNombre(QString);
    car buscarPorNombre(QString);
    car buscarPorPatente(QString);
private:
    vector<car> entradas;
    ofstream log;
};

#endif // REGISTRO_H

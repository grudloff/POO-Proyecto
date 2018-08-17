#ifndef REGISTRO_H
#define REGISTRO_H

#include <QString>
#include "stdlib.h"
#include "car.h"
#include <vector>
#include <iostream>

using namespace std;

class registro
{
public:
    registro();
    registro(QString);
    void agregar(QString,QString,QString);
    car getLast();
    car buscarPorNombre(QString);
    car buscarPorPatente(QString);
private:
    vector<car> entradas;
    ofstream log;
};

#endif // REGISTRO_H

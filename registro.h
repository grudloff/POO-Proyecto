#ifndef REGISTRO_H
#define REGISTRO_H

#include <QString>
#include "stdlib.h"
#include <iostream>
#include <vector>
#include "car.h"

using namespace std;

class registro
{
public:
    registro();
    registro(QString);
    void agregar(QString,QString,QString);
    car getLast();
    car getLast(QString);
    car buscarPorNombre(QString);
    car buscarPorPatente(QString);
private:
    vector<car> entradas;
    ofstream log;
};

#endif // REGISTRO_H

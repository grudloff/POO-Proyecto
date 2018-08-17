#ifndef REGISTRO_H
#define REGISTRO_H

#include <QString>
#include "stdlib.h"
#include <iostream>
#include <vector>
#include "car.h"
#include <fstream>

using namespace std;

class registro
{
public:
    registro();
    void agregar(QString,QString,QString);
    car* getLast();
    car* buscarPorNombre(QString);
    car* buscarPorPatente(QString);
    void check(QString);

private:
    vector<car*> entradas;
    ofstream log;
};

#endif // REGISTRO_H

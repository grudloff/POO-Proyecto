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
    /**
     * @brief Constructor por defecto, se inicializa el documento donde estara el log.
     */
    registro();
    /**
     * @brief Agrega un car al vector entradas.
     * @return Puntero al car agregado.
     */
    car* agregar(QString,QString,QString);
    /**
     * @brief Entrega el ultimo elemento del vector entradas.
     * @return puntero a car.
     */
    car* getLast();
    /**
     * @brief Busca en el vector entradas por el car con el mismo nombre.
     * @param string: nombre exacto del car que se busca.
     * @return retorna puntero a el car deseado, nulo en caso de que no este.
     */
    car* buscarPorNombre(QString);
    /**
     * @brief Busca en el vector entradas por el car con la misma patente.
     * @param string: patente exacta del car que se busca.
     * @return retorna puntero a el car deseado, nulo en caso de que no este.
     */
    car* buscarPorPatente(QString);
    /**
     * @brief Agrega al car en caso de que no exista y luego logea la entrada.
     *
     */
    car* check(QString);
    /**
     * @brief Revisa si el vector entradas esta vacio.
     * @return true si esta vacio y falso si no lo esta.
     */
    bool isEmpty();
    /**
     * @brief Quita el ultimo elemento de entradas.
     */
    void pop();
    ~registro();

private:
    /**
     * @brief Vector de cars que contiene todas las entradas registradads.
     */
    vector<car*> entradas;
    /**
     * @brief ofstream donde se logea los car detectados.
     */
    ofstream log;
};

#endif // REGISTRO_H

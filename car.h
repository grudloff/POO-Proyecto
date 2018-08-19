#ifndef CAR_H
#define CAR_H

#include <QString>

class car
{
public:
    /**
     * @brief Constructor por default, rellena con desconocido en nombre y cargo.
     * @param string: patente del car que se quiere crear.
     */
    car(QString);
    /**
     * @brief Contructor con entrada los tres atributos de car.
     */
    car(QString,QString,QString);
    /**
     * @return Entrega el QString patente del car.
     */
    QString getPatente();
    /**
     * @return Entrega el QString cargo del car.
     */
    QString getCargo();
    /**
     * @return Entrega el QString nombre del car.
     */
    QString getNombre();
    /**
     * @brief setea el atributo patente.
     */
    void setPatente(QString);
    /**
     * @brief setea el atributo cargo.
     */
    void setCargo(QString);
    /**
     * @brief setea el atributo nombre.
     */
    void setNombre(QString);
    /**
     * @brief Revisa si el car tiene la misma patente que la entrada.
     * @param string: QString de patente de entrada.
     * @return true si coinciden.
     */
    bool hasSamePatente(QString);
    /**
     * @brief Revisa si el car tiene el mismo nombre que la entrada.
     * @param string: QString de nombre de entrada.
     * @return true si coinciden.
     */
    bool hasSameNombre(QString);
private:
    /**
     * @brief QString de la patente del car.
     */
    QString patente;
    /**
     * @brief QString del cargo del usuario del car.
     */
    QString cargo;
    /**
     * @brief QString del nombre del usuario car.
     */
    QString nombre;
};

#endif // CAR_H

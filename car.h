#ifndef CAR_H
#define CAR_H

#include <QString>

class car
{
public:
    car();
    car(QString);
    QString getPatente();
    QString getCargo();
    QString getNombre();
    void setPatente(QString);
    void setCargo(QString);
    void setNombre(QString);
    bool hasSamePatente(QString);
    bool hasSameNombre(QString);
private:
    QString patente;
    QString cargo;
    QString nombre;
};

#endif // CAR_H

#include "car.h"

car::car()
{

}

car::car(QString string)
{
patente=string;
nombre="Desconocido";
cargo="Desconocido";
}

QString car::getPatente(){
    return patente;
}
QString car::getCargo(){
    return cargo;
}
QString car::getNombre(){
    return nombre;
}
void car::setPatente(QString string){
    patente=string;
}
void car::setCargo(QString string){
    cargo=string;
}
void car::setNombre(QString string){
    nombre=string;
}
bool car::hasSamePatente(QString string){
    return string==patente;
}
bool car::hasSameNombre(QString string){
    return string==nombre;
}

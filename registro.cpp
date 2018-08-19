#include "registro.h"

#include "registro_win.h"

registro::registro(){
    log.open("registro.txt");
}

car* registro::getLast(){
    return entradas.back();
}

car* registro::buscarPorNombre(QString string){
    if (entradas.empty())
        return nullptr;
    for(car* r:entradas){
        if (r->hasSameNombre(string))
            return r;
    }
    return nullptr;
}

car* registro::buscarPorPatente(QString string){
    if (entradas.empty())
        return nullptr;
    for(car* r:entradas){
        if (r->hasSamePatente(string))
            return r;
    }
    return nullptr;
}

car* registro::agregar(QString patente, QString nombre, QString cargo){
    car* cars;
    cars=buscarPorPatente(patente);
    if (cars==nullptr){
        cars = new car(patente,nombre,cargo);
        entradas.push_back(cars);
    }
    else{
        cars->setNombre(nombre);
        cars->setCargo(cargo);
    }
    return cars;
}

car* registro::check(QString patente){
    car* cars;
    cars=buscarPorPatente(patente);
    if (cars==nullptr){
        cars=agregar(patente, "Desconocido", "Desconocido");
        registro_win registro_window(nullptr,this);
        registro_window.setModal(true);
        registro_window.getPatente()->setText(patente);
        registro_window.getNombre()->setText("Desconocido");
        registro_window.getCargo()->setText("Desconocido");
        registro_window.exec();


    }
    log<<"Patente: "+patente.toStdString()+" Nombre: "+cars->getNombre().toStdString()+" Cargo: "+cars->getCargo().toStdString()<<endl;
    return cars;
}

bool registro::isEmpty(){
    return entradas.empty();
}

void registro::pop(){
    entradas.pop_back();
}

registro::~registro(){
    log.close();
}

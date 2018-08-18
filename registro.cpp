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
        if (r->getNombre()==string)
            return r;
    }
    return nullptr;
}

car* registro::buscarPorPatente(QString string){
    if (entradas.empty())
        return nullptr;
    for(car* r:entradas){
        if (r->getPatente()==string)
            return r;
    }
    return nullptr;
}

car* registro::agregar(QString patente, QString nombre, QString cargo){
    car* cars;
    cars=buscarPorPatente(patente);
    if (cars==nullptr){
        cars = new car(patente);
        cars->setNombre(nombre);
        cars->setCargo(cargo);
        entradas.push_back(cars);
    }
    else{
        cars->setNombre(nombre);
        cars->setCargo(cargo);
    }
    return cars;
}

void registro::check(QString patente){
    car* cars;
    cars=buscarPorPatente(patente);
    if (cars==nullptr){
        cars=agregar(patente, "Desconocido", "Desconocido");
        registro_win registro_window(nullptr,this);
        registro_window.setModal(true);
        registro_window.exec();

    }
    log<<"Patente: "+cars->getPatente()+" Nombre: "+cars->getNombre().toStdString()+" Cargo: "+cars->getCargo().toStdString()+"\n";


}

bool registro::isEmpty(){
    return entradas.empty();
}

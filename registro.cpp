#include "registro.h"
#include "registro_win.h"

registro::registro(){
    log.open("registro.txt");
}

car* registro::getLast(){
    return entradas.back();
}

car* registro::buscarPorNombre(QString string){

    for(car* r : entradas) {
        if(r->getNombre()==string)
            return r;
    }
    return nullptr;
}

car* registro::buscarPorPatente(QString string){
    for(car* r:entradas){
        if (r->getPatente()==string)
            return r;
    }
    return nullptr;
}

void registro::agregar(QString patente, QString nombre, QString cargo){
    car* cars;
    cars=buscarPorPatente(patente);
    if (cars==nullptr){
        car new_car(patente);
        new_car.setNombre(nombre);
        new_car.setCargo(cargo);
        entradas.push_back(&new_car);
    }
    else{
        cars->setNombre(nombre);
        cars->setCargo(cargo);
    }
}

void registro::check(QString patente){
    car* cars;
    cars=buscarPorPatente(patente);
    if (cars==nullptr){
        cars= new car(patente);
        agregar(patente, "Desconocido", "Desconocido");
        registro_win registro_window;
        registro_window.setModal(true);
        registro_window.exec();

    }
    log<<"Patente: "+patente.toStdString()+" Nombre: "+cars->getNombre().toStdString()+" Cargo: "+cars->getCargo().toStdString()+"\n";
}


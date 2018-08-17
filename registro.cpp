#include "registro.h"

registro::registro()
{

}

car registro::buscarPorNombre(QString string){
    for(std::vector<car>::iterator it = entradas.begin(); it != entradas.end(); ++it) {
        if(it->getNombre()==string)
            return *it;
    }

    entradas.push_back(new car(string));
}

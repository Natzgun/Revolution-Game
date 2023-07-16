//
// Created by msumi on 5/07/2023.
//

#include "Item.h"
#include <iostream>

void Item::actualizar() {
    if(couldown > 0){couldown--;}
}

void Item::imprimir() {
    std::cout<<"Posición: "<<this->posicion.getX()<<" , "<<this->posicion.getY()<<endl;
    //std::cout<<"Dimensión: "<<this->dimension.getX()<<" , "<<this->dimension.getY()<<endl;

}

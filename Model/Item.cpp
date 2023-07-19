//
// Created by msumi on 5/07/2023.
//

#include "Item.h"
#include <iostream>

void Item::actualizar() {
    if(couldown > 0){couldown--;}
    if(rapi> 0){
        posicion.setX(posicion.getX()+int(facing.getX()*rapi));
        posicion.setY(posicion.getY()+int(facing.getY()*rapi));
        rapi--;
    }
}

void Item::imprimir() {
    std::cout<<"Posición: "<<this->posicion.getX()<<" , "<<this->posicion.getY()<<endl;
    //std::cout<<"Dimensión: "<<this->dimension.getX()<<" , "<<this->dimension.getY()<<endl;

}

void Item::lanzar(Vector2d<float> dir, Vector2d<int> pos) {
    posicion = pos;
    facing = dir;
    rapi = 50;
}

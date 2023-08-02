//
// Created by msumi on 5/07/2023.
//

#include "Item.h"
#include <iostream>
Item::Item():Entidad(){
    couldown = 0;
    rapi = 0;
    facing = Vector2d<float>(0,0);
    stunMode = 0;
}
void Item::actualizar() {
    if(couldown > 0){couldown--;}
    if(rapi> 0){
        posicion = posicion + facing*rapi;
        //posicion.setY(posicion.getY()+facing.getY()*rapi);
        rapi--;
        if (rapi > 10)
            stunMode = true;
    }
}

void Item::imprimir() {
    std::cout<<"Posición: "<<this->posicion.getX()<<" , "<<this->posicion.getY()<<endl;
    //std::cout<<"Dimensión: "<<this->dimension.getX()<<" , "<<this->dimension.getY()<<endl;

}

void Item::lanzar(Vector2d<float> dir, Vector2d<float> pos) {
  // stun proyectile
  //si rapi = 0 eliminamos el proyectil
    posicion = pos;
    facing = dir;
    rapi = 50;
}

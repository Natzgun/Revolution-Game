//
// Created by msumi on 6/07/2023.
//

#include "Proyectil.h"
string Proyectil::clave = "sprSoup_";
Proyectil::Proyectil() {
    Proyectil::setDimension(10,20);
    Proyectil::setPosicion(0,0);
}

Proyectil::Proyectil(Vector2d<float> unitario , Vector2d<float> posicion) {
    this->velocidad = Vector2d<float>(unitario.getY() * rapi, unitario.getY() * rapi);
    this->posicion = posicion;
    Proyectil::setDimension(10,20);
    Proyectil::setPosicionCentral(this->posicion.getX()+5,this->posicion.getY()+10);
}
void Proyectil::actualizar() {
    posicion = posicion + velocidad;
}

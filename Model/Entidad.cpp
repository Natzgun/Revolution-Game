#include "Entidad.h"

Entidad::Entidad(){
    posicion = Vector2d<float>();
}
Entidad::Entidad(float x, float y){
    posicion.setX(x);
    posicion.setY(y);
}
const Vector2d<float> &Entidad::getPosicion() const {
    return posicion;
}
void Entidad::setPosicion(float x, float y) {
    posicion.setX(x);
    posicion.setY(y);
}
const Vector2d<float> &Entidad::getPosicionCentral() const {
    return posicion_central;
}
void Entidad::setPosicionCentral(float x, float y) {
    posicion_central.setX(x);
    posicion_central.setY(y);
}
const Vector2d<float> &Entidad::getDimension() const {
    return dimension;
}
void Entidad::setDimension(float x, float y) {
    dimension.setY(x);
    dimension.setY(y);
}

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

bool Entidad::checkColision(Entidad *otro) {
    if(colisionX(otro) && colisionY(otro)){
        return true;
    }
    return false;
}

bool Entidad::colisionX(Entidad *otro) {
    bool leftColisionX = otro->posicion.getX() <= this->posicion.getX() &&
                         this->posicion.getX() <= otro->posicion.getX() + otro->dimension.getX();
    bool rightColisionX = otro->posicion.getX() <= this->posicion.getX()+this->dimension.getX() &&
                          this->posicion.getX() + this->dimension.getX() <= otro->posicion.getX() + otro->dimension.getX();
    if (rightColisionX || leftColisionX){
        return true;
    }
    return false;
}
bool Entidad::colisionY(Entidad *otro) {
    bool leftColisionY = otro->posicion.getY() <= this->posicion.getY() &&
             this->posicion.getY() <= otro->posicion.getY() + otro->dimension.getY();
    bool rightColisionY = otro->posicion.getY() <= this->posicion.getY()+this->dimension.getY() &&
            this->posicion.getY() + this->dimension.getY() <= otro->posicion.getY() + otro->dimension.getY();
    if (rightColisionY || leftColisionY){
        return true;
    }
    return false;
}

void Entidad::setTop(float newY) {
  posicion.setY(newY);
}

void Entidad::setBottom(float newY) {
  posicion.setY(newY - dimension.getY());
}

void Entidad::setLeft(float newX) {
  posicion.setX(newX);
}

void Entidad::setRight(float newX) {
  posicion.setX(newX - dimension.getX());
}

void Entidad::setCenter(Vector2d<float> newCord) {
  posicion.setXY(newCord.getX() - (dimension.getX()/2) , newCord.getY() - (dimension.getY()/2));
}

float Entidad::getTop() {
  return posicion.getY();
}

float Entidad::getBottom() {
  return posicion.getY() + dimension.getY();
}

float Entidad::getLeft() {
  return posicion.getX();
}

float Entidad::getRight() {
  return posicion.getX() + dimension.getY();
}

Vector2d<float> Entidad::getCenter() {
  Vector2d<float> newPos = posicion;
  newPos.setX(newPos.getX() + (posicion.getX()/2));
  newPos.setY(newPos.getY() + (posicion.getY()/2));
  return newPos;
}

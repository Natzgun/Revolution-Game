//
// Created by pickle on 20/06/23.
//

#include "Jugador.h"

Jugador::Jugador() {
    arriba = false;
    abajo = false;
    izquierda = false;
    derecha = false;
    puntos = 0;
    vida = 1;
    arma = nullptr;

}
Jugador::Jugador(int x, int y) : Personaje(x, y) {
    arriba = false;
    abajo = false;
    izquierda = false;
    derecha = false;
    puntos = 0;
    vida = 1;
    posicion.setX(-500);
    posicion.setY(-500);
    arma = nullptr;

}
int Jugador::getPuntos() const {
    return puntos;
}
void Jugador::setPuntos(int puntos) {
    this->puntos = puntos;
}

void Jugador::setArriba(bool arriba) {
    this->arriba = arriba;
}
void Jugador::setAbajo(bool abajo) {
    this->abajo = abajo;
}
void Jugador::setIzquierda(bool izquierda) {
    this->izquierda = izquierda;
}
void Jugador::setDerecha(bool derecha) {
    this->derecha = derecha;
}

void Jugador::actualizar() {
    if(arriba){
        posicion.setY(posicion.getY() + 5);
    }
    if(abajo){
        posicion.setY(posicion.getY() - 5);
    }
    if(izquierda){
        posicion.setX(posicion.getX() - 5);
    }
    if(derecha){
        posicion.setX(posicion.getX() + 5);
    }

    //  Actualizar estado:

    if (arma!=nullptr && disparando/*jugador tiene arma y presiona disparar*/)
      estado = 'd';
    else if(!arriba && !abajo && !izquierda && !derecha)
      estado = 'q';
    else
      estado = 'm';

}

void Jugador::imprimir() {
    std::cout << posicion.getX() << ", " << posicion.getY() << std::endl;
}

void Jugador::setDisparando(bool disparando) {
  this->disparando = disparando;
}

//
// Created by pickle on 20/06/23.
//

#include "Jugador.h"
#include "GameWorld.h"
#include <string>

Jugador::Jugador() {
    arriba = false;
    abajo = false;
    izquierda = false;
    derecha = false;
    puntos = 0;
    vida = 1;
    arma = nullptr;
    facing.setXY(0,1);
}
Jugador::Jugador(float x, float y) : Personaje(x, y) {
    arriba = false;
    abajo = false;
    izquierda = false;
    derecha = false;
    puntos = 0;
    vida = 1;
    arma = nullptr;
    facing.setXY(0,1);

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
        posicion.setY(posicion.getY() - 5);
//        facing.setXY(0,1);
    }
    if(abajo){
        posicion.setY(posicion.getY() + 5);
//        facing.setXY(0,-1);
    }
    if(izquierda){
        posicion.setX(posicion.getX() - 5);
//        facing.setXY(-1,0);
    }
    if(derecha){
        posicion.setX(posicion.getX() + 5);
//        facing.setXY(1,0);
    }

    //  Actualizar estado jugador:

    /*if (arma!=nullptr && disparando){
      estado = PersonajeEstado::Disparando;
      arma->usar(facing,posicion);
    }
    else if(recogiendo) {
      estado = PersonajeEstado::Recogiendo;
    }
    else if(!arriba && !abajo && !izquierda && !derecha)
      estado = PersonajeEstado::Quieto;
    else if(lanzando) {
      arma->lanzar(facing, posicion);
      estado = PersonajeEstado::Lanzando;
    }
    else
      estado = PersonajeEstado::Moviendose;*/


    // estado de arma

    if(arma == nullptr)
      estadoArma = PersonajeEstado::Desarmado;
    else
      estadoArma = PersonajeEstado::Pistola;
}

void Jugador::imprimir() {
    std::cout << posicion.getX() << ", " << posicion.getY() << std::endl;
}

void Jugador::setDisparando(bool disparando) {
  this->disparando = disparando;
}

Vector2d<float> Jugador::getPos() {
  return posicion;
}

PersonajeEstado Jugador::getEstado() {
  return estado;
}

PersonajeEstado Jugador::getEstadoArma() {
  return estadoArma;
}

void Jugador::setFacing(Vector2d<float>a) {
  facing = a;
}

void Jugador::disparar() {
  string asd;
  switch (estado) {
    case PersonajeEstado::Quieto: asd= "Quieto";
    case PersonajeEstado::Moviendose: asd= "Moviendose";
    case PersonajeEstado::Disparando: asd= "Disparando";
    case PersonajeEstado::Lanzando: asd= "Lanzando";
    case PersonajeEstado::Recogiendo: asd= "Recogiendo";

    case PersonajeEstado::Desarmado: asd= "Disparando";
    case PersonajeEstado::Pistola: asd= "Quieto";
    case PersonajeEstado::Escopeta: asd= "Moviendose";
  }

  if (arma != nullptr && estado != PersonajeEstado::Quieto){
    std::cout<<asd<<"--"<<(arma != nullptr)<<std::endl;
    estado = PersonajeEstado::Disparando;
    arma->usar(facing,posicion);
  }
}

void Jugador::lanzar() {
  if (arma!=nullptr && estado != PersonajeEstado::Lanzando){
    estado = PersonajeEstado::Lanzando;
    arma->lanzar(facing, posicion);
  }
}

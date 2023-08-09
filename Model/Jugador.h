//
// Created by pickle on 20/06/23.
//

#ifndef REVOLUTION_GAME_JUGADOR_H
#define REVOLUTION_GAME_JUGADOR_H
#include "Personaje.h"
#include <iostream>
#include <memory>
#include "../Util/Estados.h"
#include "AnimacionM.h"
#include <tuple>

class Jugador: public Personaje {
private:
  bool arriba, abajo, izquierda, derecha;
  bool disparando, recogiendo, lanzando;
  Vector2d<float> facing;
  int puntos;

  static tuple<int,int,string> ATorso;
  static tuple<int,int,string> APiernas;

  AnimacionM piernas;
  AnimacionM torso;

public:
    Jugador();
    Jugador(float x, float y);

    void setArriba(bool arriba);
    void setAbajo(bool abajo);
    void setIzquierda(bool izquierda);
    void setDerecha(bool derecha);
    void setDisparando(bool);
    void disparar();
    void lanzar();

    int getPuntos() const;
    void setPuntos(int puntos);
    Vector2d<float> getPos();
    PersonajeEstado getEstado();
    PersonajeEstado getEstadoArma();

    void setFacing(Vector2d<float>);

    void actualizar() override;
    //void cogerArma(&GameWorld); // incompleto

    void imprimir();
    ~Jugador()override=default;
};

#endif //REVOLUTION_GAME_JUGADOR_H

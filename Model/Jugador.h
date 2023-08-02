//
// Created by pickle on 20/06/23.
//

#ifndef REVOLUTION_GAME_JUGADOR_H
#define REVOLUTION_GAME_JUGADOR_H
#include "Personaje.h"
#include <iostream>
#include <memory>
#include "../Util/Estados.h"

class Jugador: protected Personaje {
private:
    bool arriba, abajo, izquierda, derecha;
    bool disparando, recogiendo, lanzando;
    Vector2d<float> facing;
    //bool armaDisponible;
    int puntos;
    //char estado; // quieto moviendose disparando
    PersonajeEstado estado;
    PersonajeEstado estadoArma ;

public:
    Jugador();
    Jugador(float x, float y);

    void setArriba(bool arriba);
    void setAbajo(bool abajo);
    void setIzquierda(bool izquierda);
    void setDerecha(bool derecha);
    void setDisparando(bool);

    int getPuntos() const;
    void setPuntos(int puntos);
    Vector2d<float> getPos();
    PersonajeEstado getEstado();
    PersonajeEstado getEstadoArma();

    void setFacing(Vector2d<float>);

    void actualizar() override;
    //void cogerArma(&Juego); // incompleto

    void imprimir();
    ~Jugador()override=default;
};

#endif //REVOLUTION_GAME_JUGADOR_H

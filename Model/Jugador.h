//
// Created by pickle on 20/06/23.
//

#ifndef REVOLUTION_GAME_JUGADOR_H
#define REVOLUTION_GAME_JUGADOR_H
#include "Personaje.h"
#include <iostream>
#include <memory>

class Jugador: protected Personaje {
private:
    bool arriba, abajo, izquierda, derecha;
    bool disparando, lclick;
    Vector2d<float> facing;
    //bool armaDisponible;
    unique_ptr<Item> arma;
    int puntos;
    char estado; // quieto moviendose disparando
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

    void actualizar() override;
    //void cogerArma(&Juego); // incompleto

    void imprimir();
    ~Jugador()override=default;
};

#endif //REVOLUTION_GAME_JUGADOR_H

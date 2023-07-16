//
// Created by pickle on 20/06/23.
//

#ifndef REVOLUTION_GAME_JUGADOR_H
#define REVOLUTION_GAME_JUGADOR_H
#include "Personaje.h"
#include <iostream>

class Jugador: protected Personaje {
private:
    bool arriba, abajo, izquierda, derecha;
    int puntos;
public:
    Jugador();
    Jugador(int x, int y);
    void setArriba(bool arriba);
    void setAbajo(bool abajo);
    void setIzquierda(bool izquierda);
    void setDerecha(bool derecha);

    int getPuntos() const;
    void setPuntos(int puntos);

    void actualizar() override;
    //void coger arma(&Juego);{
    void mostrar();
    ~Jugador()override=default;
};

#endif //REVOLUTION_GAME_JUGADOR_H

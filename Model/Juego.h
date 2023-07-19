
#ifndef REVOLUTION_GAME_JUEGO_H
#define REVOLUTION_GAME_JUEGO_H

#include "Jugador.h"
#include "Stage.h"

class Juego {
public:
    Jugador* p1;
    Stage nivel;
    string matrizEscenario; //useless
    //Escenario(Enemigos, obstaculos, items);
    //ProyectilesEnemigos
    //Proyectiles
    //
    Juego();
    Juego(string mEscenario);
    void actualizar();
    //Verificar colisiones();
    //if(item.vel == 0) es intangible y podra ser recogido por algun personaje
};

#endif //REVOLUTION_GAME_JUEGO_H
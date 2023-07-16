
#ifndef REVOLUTION_GAME_JUEGO_H
#define REVOLUTION_GAME_JUEGO_H

#include "Jugador.h"

class Juego {
public:
    Jugador* p1;
    //Escenario(Enemigos, obstaculos, items);
    //ProyectilesEnemigos
    //Proyectiles
    //

    Juego();
    void actualizar();
    //Verificar colisiones();
    //if(item.vel == 0) es intangible y podra ser recogido por algun personaje
};


#endif //REVOLUTION_GAME_JUEGO_H

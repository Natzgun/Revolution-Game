
#ifndef REVOLUTION_GAME_GAMEWORLD_H
#define REVOLUTION_GAME_GAMEWORLD_H

#include "Model.h"
#include "Jugador.h"
#include "Stage.h"
#include "memory"
#include <iostream>

class GameWorld : public Mdl::Model{
public:
    std::unique_ptr<Jugador> p1 = nullptr;
    Stage *nivel;
    static string pathNivel;
    static vector<std::unique_ptr<Proyectil>> proyectiles;
    //Escenario(Enemigos, obstaculos, items);
    //ProyectilesEnemigos
    //Proyectiles
    GameWorld();
    GameWorld(string);
    void actualizar() override;
    void handleEvent(std::string) override;
    ~GameWorld(){delete nivel;}

    //Verificar colisiones();
    //if(item.vel == 0) es intangible y podra ser recogido por algun personaje
};

#endif //REVOLUTION_GAME_GAMEWORLD_H
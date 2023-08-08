//
// Created by msumi on 28/06/2023.
//

#ifndef REVOLUTION_GAME_PERSONAJE_H
#define REVOLUTION_GAME_PERSONAJE_H

#include <memory>
#include "Entidad.h"
#include "Item.h"
#include "../Util/Estados.h"

class Personaje : public Entidad{
protected:
    //static Vector2d<int> dimension;
    unsigned int vida;
    unsigned int rapidez;
    Vector2d<int> velocidad;
public:
  PersonajeEstado estado;
  PersonajeEstado estadoArma ;
  std::unique_ptr<Item> arma;
    Personaje() : Entidad(){};
    Personaje(int x, int y) : Entidad(x, y){
    };
    virtual void actualizar()=0;
    virtual ~Personaje()override=default;
};
//Vector2d<int> Personaje::dimension = Vector2d(5,10);

#endif //REVOLUTION_GAME_PERSONAJE_H

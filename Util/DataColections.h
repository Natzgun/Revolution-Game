//
// Created by msumi on 31/07/2023.
//

#ifndef REVOLUTION_GAME_DATACOLECTIONS_H
#define REVOLUTION_GAME_DATACOLECTIONS_H
#include "Estados.h"
#include "Vector2d.h"

class PersonajeData {
public:
  Vector2d<float> pos;
  Vector2d<float> dir;
  PersonajeEstado estado;
  PersonajeData();
};


#endif //REVOLUTION_GAME_DATACOLECTIONS_H

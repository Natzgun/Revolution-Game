//
// Created by pickle on 01/08/23.
//

#ifndef REVOLUTION_GAME_OBSTACULO_H
#define REVOLUTION_GAME_OBSTACULO_H


#include "Entidad.h"

class Obstaculo: Entidad {
public:
  Obstaculo(float x, float y, float dimX , float dimY);
  void actualizar();
};


#endif //REVOLUTION_GAME_OBSTACULO_H

//
// Created by pickle on 01/08/23.
//

#include "Obstaculo.h"

void Obstaculo::actualizar() {
}

Obstaculo::Obstaculo(float x, float y, float dimX, float dimY) {
  this->setDimension(dimX*40,dimY*40);
  this->setPosicionCentral(x*40,y*40);
}

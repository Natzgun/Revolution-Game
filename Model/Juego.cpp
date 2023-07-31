//
// Created by msumi on 27/06/2023.
//

#include "Juego.h"
vector<unique_ptr<Proyectil>> Juego::proyectiles = {};
Juego::Juego() {
  p1 = make_unique<Jugador>(500,500);
  nivel = Stage("../Resources/matrizStage.csv");
}
Juego::Juego(string path) {
  p1 = make_unique<Jugador>();
  nivel = Stage(path);
}
void Juego::actualizar() const {
  p1->actualizar();
  for(const auto & proyectile : proyectiles){
    proyectile->actualizar();
  }
}

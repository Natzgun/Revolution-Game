//
// Created by msumi on 27/06/2023.
//

#include "Juego.h"
string Juego::pathNivel = "../Resources/Niveles/stage1.csv";
vector<unique_ptr<Proyectil>> Juego::proyectiles = {};
Juego::Juego() {
  p1 = make_unique<Jugador>(500,500);
  p1->arma = std::make_unique<Firegun>();
  nivel = new Stage(pathNivel);
}
Juego::Juego(string path) {
  p1 = make_unique<Jugador>();
  nivel = new Stage(path);
}
void Juego::actualizar() {
  p1->actualizar();
  for(size_t i = 0; i<Juego::proyectiles.size();i++){
    proyectiles[i]->actualizar();
  }
  nivel->actualizar();
}


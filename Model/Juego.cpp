//
// Created by msumi on 27/06/2023.
//

#include "Juego.h"
string Juego::pathNivel = "../Resources/Niveles/Nivel-1.csv";
vector<unique_ptr<Proyectil>> Juego::proyectiles = {};
Juego::Juego() {
  p1 = new Jugador();
  nivel = Stage(pathNivel);
}
Juego::Juego(string path) {
  p1 = new Jugador();
  nivel = Stage(path);
}
void Juego::actualizar() {
  p1->actualizar();
  for(int i = 0; i<Juego::proyectiles.size();i++){
    proyectiles[i]->actualizar();
  }
  nivel.actualizar();
}


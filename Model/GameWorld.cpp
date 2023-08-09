#include "GameWorld.h"

string GameWorld::pathNivel = "../Resources/Niveles/stage1.csv";
vector<unique_ptr<Proyectil>> GameWorld::proyectiles = {};

GameWorld::GameWorld() {
  p1 = make_unique<Jugador>(500,500);
  p1->arma = std::make_unique<Firegun>();
  nivel = new Stage(pathNivel);
}

GameWorld::GameWorld(string path) {
  p1 = make_unique<Jugador>();
  nivel = new Stage(path);
}

void GameWorld::actualizar() {
  p1->actualizar();
  for(size_t i = 0; i < GameWorld::proyectiles.size(); i++){
    proyectiles[i]->actualizar();
  }
  nivel->actualizar();
}

void GameWorld::handleEvent(std::string evento) {
  if(evento == "lclick")
    p1->disparar();
  else if(evento == "rclick")
    p1->lanzar();
}


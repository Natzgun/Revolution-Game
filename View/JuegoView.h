//
// Created by msumi on 19/07/2023.
//

#ifndef REVOLUTION_GAME_JUEGOVIEW_H
#define REVOLUTION_GAME_JUEGOVIEW_H

#include "JugadorView.h"
#include "ProyectilV.h"
#include "Escenario.h"
#include "States/GameState.h"
#include <memory>
#include "SFML/Audio.hpp"

class JuegoView {
public:
  std::unique_ptr<JugadorView> j1;
  std::unique_ptr<JugadorView> j2;
  std::vector<std::unique_ptr<ProyectilV>> proyectiles;
  sf::RenderTexture targetTexture;
  sf::Sprite sprite;
  sf::Music musicaGame;

  Escenario* e1;
  //sf::FloatRect rectanguloMovimiento;
  JuegoView();
  void actualizar();
  const sf::Sprite & getsprite() const;
  void initMusic();
  sf::Music &getMusic();
  ~JuegoView();
};

#endif //REVOLUTION_GAME_JUEGOVIEW_H

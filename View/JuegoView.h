//
// Created by msumi on 19/07/2023.
//

#ifndef REVOLUTION_GAME_JUEGOVIEW_H
#define REVOLUTION_GAME_JUEGOVIEW_H

#include "JugadorView.h"
#include "ProyectilV.h"

class JuegoView {
public:
  JugadorView* j1;
  std::vector<ProyectilV> proyectiles;
  sf::RenderTexture targetTexture;
  sf::Sprite sprite;
  JuegoView();
  void actualizar();
  const sf::Sprite & getsprite() const;
  ~JuegoView();
};

#endif //REVOLUTION_GAME_JUEGOVIEW_H

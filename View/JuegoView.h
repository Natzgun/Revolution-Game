//
// Created by msumi on 19/07/2023.
//

#ifndef REVOLUTION_GAME_JUEGOVIEW_H
#define REVOLUTION_GAME_JUEGOVIEW_H

#include "JugadorView.h"
#include "ProyectilV.h"
#include <memory>

class JuegoView {
public:
  std::unique_ptr<JugadorView> j1;
  std::unique_ptr<JugadorView> j2;
  std::vector<std::unique_ptr<ProyectilV>> proyectiles;
  sf::RenderTexture targetTexture;
  sf::Sprite sprite;
  JuegoView();
  void actualizar();
  void handleJuegoEvents();
  bool j1_Lclick();
  bool j1_Rclick();
  const sf::Sprite & getsprite() const;
  ~JuegoView();
};

#endif //REVOLUTION_GAME_JUEGOVIEW_H

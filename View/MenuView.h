//
// Created by natzgun on 25/07/23.
//

#ifndef REVOLUTION_GAME_MENUVIEW_H
#define REVOLUTION_GAME_MENUVIEW_H

#include "Menu.h"

class MenuView {
public:
  Menu* mn1;
  sf::RenderTexture targetTexture;
  sf::Sprite sprite;
  MenuView();
  void actualizar();
  const sf::Sprite& getSprite() const;
  ~MenuView();
};


#endif //REVOLUTION_GAME_MENUVIEW_H

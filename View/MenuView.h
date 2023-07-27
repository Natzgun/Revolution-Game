//
// Created by natzgun on 25/07/23.
//

#ifndef REVOLUTION_GAME_MENUVIEW_H
#define REVOLUTION_GAME_MENUVIEW_H

#include <array>
#include "Menu.h"
#include "Animation.h"

class MenuView {
public:
  Menu* mn1;
  sf::RenderTexture targetTexture;
  sf::Sprite sprite;

  std::array<sf::Texture,3> buttonTextures;
  std::array<sf::Sprite,3> buttons;
  int selectedItem;

  MenuView();
  void actualizar();
  const sf::Sprite& getSprite() const;
  ~MenuView();

  void handleButtonClick(const sf::Vector2f& mousePosition);
};


#endif //REVOLUTION_GAME_MENUVIEW_H

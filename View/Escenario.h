//
// Created by natzgun on 1/08/23.
//

#ifndef REVOLUTION_GAME_ESCENARIO_H
#define REVOLUTION_GAME_ESCENARIO_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <optional>

class Escenario: public sf::Drawable {
public:
  sf::Texture backgroundTexture;
  std::optional<sf::Sprite> backgroundSprite;
  sf::View camara;

  Escenario();
  void setBackground();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::Sprite &getSprite();
  ~Escenario();
};


#endif //REVOLUTION_GAME_ESCENARIO_H

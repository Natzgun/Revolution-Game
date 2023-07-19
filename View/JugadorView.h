#ifndef REVOLUTION_GAME_JUGADORVIEW_H
#define REVOLUTION_GAME_JUGADORVIEW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"
#include "../Util/Vector2d.h"
#include <vector>

using std::string;

class JugadorView: public sf::Drawable {
public:
  Animation *animation;
  static std::vector<sf::Texture> torso;
  static std::vector<sf::Texture> piernas;

  JugadorView(int, float,std::string);
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  void updateA();
  sf::Sprite &getSprite();
};

#endif //REVOLUTION_GAME_JUGADORVIEW_H

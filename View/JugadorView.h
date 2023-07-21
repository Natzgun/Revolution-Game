#ifndef REVOLUTION_GAME_JUGADORVIEW_H
#define REVOLUTION_GAME_JUGADORVIEW_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

using std::string;

class JugadorView: public sf::Drawable {
public:
  Animation *animationP;
  Animation *animationT;

  static std::vector<sf::Texture> quieto;
  static std::vector<sf::Texture> moviendose;
  static std::vector<sf::Texture> disparando;
  static std::vector<sf::Texture> lanzando;
  static std::vector<sf::Texture> piernas;

  static void init();
  JugadorView();
  void setPosicion(float, float) const ;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  void updateA();
  sf::Sprite &getSprite() const;
  ~JugadorView();
};

#endif //REVOLUTION_GAME_JUGADORVIEW_H

#ifndef REVOLUTION_GAME_PROYECTILV_H
#define REVOLUTION_GAME_PROYECTILV_H

#include <SFML/Graphics.hpp>
#include "Animation.h"

class ProyectilV: public sf::Drawable {
public:
  //Animation *animation;
  sf::Sprite sprite;
  static sf::Texture normal;
  static sf::Texture especial;

  static void init();
  ProyectilV();
  void setPosicion(float, float) ;
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  void updateA();
  sf::Sprite &getSprite();
  ~ProyectilV()= default;
};


#endif //REVOLUTION_GAME_PROYECTILV_H

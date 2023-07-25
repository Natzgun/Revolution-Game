#ifndef REVOLUTION_GAME_JUGADORVIEW_H
#define REVOLUTION_GAME_JUGADORVIEW_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <array>

using std::string;

class JugadorView: public sf::Drawable {
public:
  bool up, down, right, left;
  int estado;
  float ang = 0.7f;
  Animation *animationP;
  Animation *animationT;

  static std::array<char,5> estados;
  static std::vector<sf::Texture> quieto;
  static std::vector<sf::Texture> moviendose;
  static std::vector<sf::Texture> disparando;
  static std::vector<sf::Texture> lanzando;
  static std::vector<sf::Texture> piernas;
  static std::vector<sf::Texture> recogiendo;

  static void init();
  JugadorView();
  void setPosicion(float, float) const;
  void setDireccion(float, float) ;
  void capturarEventos();
  void animar();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  void actualizar(sf::Vector2f, sf::Vector2i);
  sf::Sprite &getSprite() const;
  ~JugadorView();
};

#endif //REVOLUTION_GAME_JUGADORVIEW_H

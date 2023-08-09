#ifndef REVOLUTION_GAME_PERSONAJEVIEW_H
#define REVOLUTION_GAME_PERSONAJEVIEW_H

#include "../Util/Vector2d.h"
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <array>
#include <memory>

class PersonajeView: public sf::Drawable {
public:
  bool up, down, right, left;
  std::unique_ptr<Animation> animationP;
  std::unique_ptr<Animation> animationT;

  static std::vector<sf::Texture> quieto;
  static std::vector<sf::Texture> moviendose;
  static std::vector<sf::Texture> disparando;
  static std::vector<sf::Texture> lanzando;
  static std::vector<sf::Texture> piernas;
  static std::vector<sf::Texture> recogiendo;

  static void init();
  PersonajeView();
  void setPosicion(Vector2d<float>) const;
  void setDireccion(Vector2d<float> movimiento, Vector2d<float> mirada) const;
  virtual void animar();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  virtual void actualizar();
  virtual ~PersonajeView();
};


#endif //REVOLUTION_GAME_PERSONAJEVIEW_H

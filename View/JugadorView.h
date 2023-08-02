#ifndef REVOLUTION_GAME_JUGADORVIEW_H
#define REVOLUTION_GAME_JUGADORVIEW_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <array>
#include "PersonajeView.h"

using std::string;

class JugadorView: public PersonajeView {
public:
  bool lclick, rclick;

  JugadorView();
  void handleKeyEvents();
  bool presionarLclick();
  bool presionarRclick();
  void animar() override;
  void actualizar(sf::Vector2f, sf::Vector2i) override;
  ~JugadorView() override = default;
};

#endif //REVOLUTION_GAME_JUGADORVIEW_H

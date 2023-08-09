#ifndef REVOLUTION_GAME_JUEGOVIEW_H
#define REVOLUTION_GAME_JUEGOVIEW_H

#include "EstadoView.h"
#include "JugadorView.h"
#include "ProyectilV.h"
#include <memory>

class JuegoView : public EstadoView {
public:
  JuegoView(std::queue<std::string>*);
  ~JuegoView() = default;
  void capturarEventos(sf::RenderWindow&,sf::Event&) override;
};

#endif //REVOLUTION_GAME_JUEGOVIEW_H

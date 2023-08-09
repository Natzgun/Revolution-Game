#ifndef REVOLUTION_GAME_ESTADOVIEW_H
#define REVOLUTION_GAME_ESTADOVIEW_H

#include <SFML/Graphics.hpp>
#include <queue>
#include <string>

class EstadoView {
protected:
  std::queue<std::string>* coladeEventos;
public:
  EstadoView(std::queue<std::string>*);
  ~EstadoView() = default;
  virtual void capturarEventos(sf::RenderWindow&,sf::Event&) = 0;
};


#endif //REVOLUTION_GAME_ESTADOVIEW_H

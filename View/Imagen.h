#ifndef REVOLUTION_GAME_IMAGEN_H
#define REVOLUTION_GAME_IMAGEN_H

#include <vector>
#include <SFML/Graphics/Texture.hpp>

class Imagen {
protected:
  sf::Texture disenio;
  std::vector<int> dimension;
  void dibujar();
};


#endif //REVOLUTION_GAME_IMAGEN_H

#ifndef REVOLUTION_GAME_RENDER_H
#define REVOLUTION_GAME_RENDER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <iostream>
#include "../Util/Vector2d.h"

class Render {
public:
  static Render* GetInstance();
  void cargarTexturas(const std::string& clave, const std::string& path, const int& cantidad);
  void setPov(const Vector2d<float>&);
  void dibujar(const std::string& clave, int indice, const Vector2d<float>& pos, const Vector2d<float>& dir);
private:
  std::unordered_map<std::string, std::vector<sf::Texture>> texturas;
  sf::Sprite sprite;
  sf::View pov;
  sf::RenderTexture targetTexture;

  static Render* render;
  //Constructores
  Render() {}
  Render(const Render&) = delete;
  void operator=(const Render&) = delete;
};


#endif //REVOLUTION_GAME_RENDER_H

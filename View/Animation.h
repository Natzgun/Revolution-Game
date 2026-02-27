#ifndef REVOLUTION_GAME_ANIMATION_H
#define REVOLUTION_GAME_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <type_traits>
#include <optional>

class Animation {
private:
  int numFrames{};
  float frameTime;
  int currentFrame{};
  sf::Clock clock;
  std::vector<sf::Texture>* frames{};
  std::optional<sf::Sprite> sprite;
  sf::Vector2f a;
public:
  Animation();
  Animation(std::vector<sf::Texture>* _frames);
  void setTetures(std::vector<sf::Texture>* _frames);
  //void animar();
  bool animar();
  sf::Sprite &getSprite();

  static std::vector<sf::Texture> cargarImagenes(const int& n, const std::string& path);
  static sf::Texture cargarImagen(const std::string& path);
  static void setPos(sf::Sprite&, const float&, const float&);
  static void setDir(sf::Sprite& sp, float x, float y){
    sp.setRotation(sf::degrees(std::atan2(y, x)*180.0f/3.14f));
  }
};

#endif //REVOLUTION_GAME_ANIMATION_H
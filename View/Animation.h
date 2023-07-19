#ifndef REVOLUTION_GAME_ANIMATION_H
#define REVOLUTION_GAME_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <vector>

class Animation {
private:
  int numFrames;
  float frameTime;
  int currentFrame;
  sf::Clock clock;
  std::vector<sf::Texture>* frames;
  sf::Sprite sprite;
public:
  Animation(){};
  Animation(std::vector<sf::Texture>* _frames);
  void setTetures(std::vector<sf::Texture>* _frames);
  void animar();
  sf::Sprite &getSprite();

  static std::vector<sf::Texture> cargarImagenes(int n, std::string path);
};

#endif //REVOLUTION_GAME_ANIMATION_H
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
  std::vector<sf::Texture> frames;
  sf::Sprite sprite;
public:
  Animation(int numFrames, float frameTime, std::string path);
  void animar();
  sf::Sprite &getSprite();
};


#endif //REVOLUTION_GAME_ANIMATION_H

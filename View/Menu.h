#ifndef REVOLUTION_GAME_MENU_H
#define REVOLUTION_GAME_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Animation.h"

class Menu: public sf::Drawable {
public:
  Animation *animaMenu;

  static std::vector<sf::Texture> menuTexture;

  sf::Font font;
  sf::Music music;
  //sf::Texture backgroundTexture;
  sf::Sprite backgroundSprite;
  std::vector<sf::Text> buttons;
  int selectedItem;

  Menu();
  ~Menu();
  static void init();
  void initMusic();
  // void setBackground();
  void updateAnimation();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::Sprite &getSprite() const;
  sf::Music &getMusic();
};


#endif //REVOLUTION_GAME_MENU_H

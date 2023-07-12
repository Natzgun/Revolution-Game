#ifndef REVOLUTION_GAME_MENU_H
#define REVOLUTION_GAME_MENU_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

class Menu {
  sf::Font font;
  sf::Music music;
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSprite;
  std::vector<sf::Text> buttons;
  int selectedItem;
public:
  Menu();
  ~Menu();
  void initMusic();
  void setBackground();
  sf::Sprite &getSprite();
  sf::Music &getMusic();
};


#endif //REVOLUTION_GAME_MENU_H

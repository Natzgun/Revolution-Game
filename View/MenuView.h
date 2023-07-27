//
// Created by natzgun on 25/07/23.
//

#ifndef REVOLUTION_GAME_MENUVIEW_H
#define REVOLUTION_GAME_MENUVIEW_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
//#include "Menu.h"
#include "Animation.h"

class MenuView: public sf::Drawable {
public:
  Animation *animaMenu;
  static std::vector<sf::Texture> menuTexture;
  sf::Music music;
  sf::Texture backgroundTexture;
  sf::Sprite backgroundSprite;

  //Menu* mn1;
  sf::RenderTexture targetTexture;
  sf::Sprite sprite;

  // Esto de aqui es para los botones
  std::array<sf::Texture,3> buttonTextures;
  std::array<sf::Sprite,3> buttons;
  int selectedItem;

  MenuView();
  void actualizar();
  const sf::Sprite& getSprite() const;
  ~MenuView();

  static void init();
  void initMusic();
  void updateAnimation();
  void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
  sf::Music &getMusic();

  void handleButtonClick(const sf::Vector2f& mousePosition);
};


#endif //REVOLUTION_GAME_MENUVIEW_H

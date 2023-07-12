#include "Menu.h"

Menu::Menu() {
  setBackground();
  initMusic();
}

Menu::~Menu() {
  music.stop();
}

void Menu::initMusic() {
  if (!music.openFromFile("../Resources/amazonico.ogg"))
    throw std::runtime_error("No se pudo cargar la musica");
  music.setVolume(100);
  music.setVolume(music.getVolume() / 2);
  music.play();

}

sf::Sprite &Menu::getSprite() {
  return backgroundSprite;
}

void Menu::setBackground() {
  if (!backgroundTexture.loadFromFile("../Resources/wallMenu2.jpg"))
  {
    // Error al cargar la imagen de fondo
    throw std::runtime_error("No se pudo cargar la imagen");
  }
  backgroundSprite.setTexture(backgroundTexture);
}

sf::Music &Menu::getMusic() {
    return music;
}

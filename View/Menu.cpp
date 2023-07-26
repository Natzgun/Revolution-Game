#include "Menu.h"

std::vector<sf::Texture> Menu::menuTexture = {};

Menu::Menu() {
  //setBackground();
  this->animaMenu = new Animation(&menuTexture);
  this->animaMenu->getSprite().setScale(1280/960.0,720/540.0);
  initMusic();
}

void Menu::updateAnimation() {
  this->animaMenu->animar();
}

Menu::~Menu() {
  delete animaMenu;
  music.stop();
}

void Menu::initMusic() {
  if (!music.openFromFile("../Resources/amazonico.ogg"))
    throw std::runtime_error("No se pudo cargar la musica");
  music.setVolume(100);
  music.setVolume(music.getVolume() / 2);
  music.play();
}

sf::Sprite &Menu::getSprite() const {
  return this->animaMenu->getSprite();
}

/*void Menu::setBackground() {
  if (!backgroundTexture.loadFromFile("../Resources/wallMenu2.jpg"))
  {
    // Error al cargar la imagen de fondo
    throw std::runtime_error("No se pudo cargar la imagen");
  }
  backgroundSprite.setTexture(backgroundTexture);
}*/

sf::Music &Menu::getMusic() {
    return music;
}

void Menu::init() {
  menuTexture = Animation::cargarImagenes(31, "../Resources/MenuPrincipal/wallMenu_100ms_");
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(animaMenu->getSprite(), states);
}

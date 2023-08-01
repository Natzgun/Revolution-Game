//
// Created by natzgun on 25/07/23.
//

#include <iostream>
#include "MenuView.h"

std::vector<sf::Texture> MenuView::menuTexture = {};

MenuView::MenuView() {
  //MenuView::init();
  //this->mn1 = new Menu();
  this->animaMenu = new Animation(&menuTexture);
  this->animaMenu->getSprite().setScale(1280/960.0,720/540.0);
  initMusic();

  targetTexture.create(1280,720);
  buttonTextures[0] = Animation::cargarImagen("../Resources/revolutionLogo.png");
  buttonTextures[1] = Animation::cargarImagen("../Resources/startGame.png");
  buttonTextures[2] = Animation::cargarImagen("../Resources/Exit.png");
  buttons[0].setTexture(buttonTextures[0]);
  buttons[1].setTexture(buttonTextures[1]);
  buttons[2].setTexture(buttonTextures[2]);

  buttons[0].setPosition(140,100);
  buttons[1].setPosition(160,450);
  buttons[2].setPosition(160,550);
  selectedItem = false;
}

void MenuView::actualizar() {
  //mn1->updateAnimation();
  updateAnimation();
  targetTexture.clear();
  //targetTexture.draw(*mn1);
  targetTexture.draw(animaMenu->getSprite());
  targetTexture.draw(buttons[0]);
  targetTexture.draw(buttons[1]);
  targetTexture.draw(buttons[2]);
  targetTexture.display();
  sprite.setTexture(targetTexture.getTexture());
}

const sf::Sprite &MenuView::getSprite() const {
  return sprite;
}

MenuView::~MenuView() {
  //delete mn1;
  delete animaMenu;
  music.stop();
}

void MenuView::handleButtonClick(const sf::Vector2f &mousePosition) {
  if (buttons[1].getGlobalBounds().contains(mousePosition)) {
    buttons[1].setScale(1.5,1.5);
    std::cout << "Iniciar el juego...\n";
    selectedItem = true;
  }
  else if (buttons[2].getGlobalBounds().contains(mousePosition)) {
    buttons[2].setScale(1.5,1.5);
    std::cout << "Salir del juego...\n";
  }
}

void MenuView::init() {
  menuTexture = Animation::cargarImagenes(31, "../Resources/MenuPrincipal/wallMenu_100ms_");
}

void MenuView::initMusic() {
  if (!music.openFromFile("../Resources/amazonico.ogg"))
    throw std::runtime_error("No se pudo cargar la musica");
  music.setVolume(100);
  music.setVolume(music.getVolume() / 2);
  music.play();
}

void MenuView::updateAnimation() {
  this->animaMenu->animar();
}

void MenuView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(animaMenu->getSprite(), states);
}

sf::Music &MenuView::getMusic() {
  return music;
}

void MenuView::setSelectionB(bool s) {
  selectedItem = s;
}

bool &MenuView::getSelectionB() {
  return selectedItem;
}
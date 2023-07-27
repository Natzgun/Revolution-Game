//
// Created by natzgun on 25/07/23.
//

#include "MenuView.h"

MenuView::MenuView() {
  Menu::init();
  this->mn1 = new Menu();
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
}

void MenuView::actualizar() {
  mn1->updateAnimation();
  targetTexture.clear();
  targetTexture.draw(*mn1);
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
  delete mn1;
}

void MenuView::handleButtonClick(const sf::Vector2f &mousePosition) {

}

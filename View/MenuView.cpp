//
// Created by natzgun on 25/07/23.
//

#include "MenuView.h"

MenuView::MenuView() {
  Menu::init();
  this->mn1 = new Menu();
  targetTexture.create(1280,720);
}

void MenuView::actualizar() {
  mn1->updateAnimation();
  targetTexture.clear();
  targetTexture.draw(*mn1);
  targetTexture.display();
  sprite.setTexture(targetTexture.getTexture());
}

const sf::Sprite &MenuView::getSprite() const {
  return sprite;
}

MenuView::~MenuView() {
  delete mn1;
}

//
// Created by msumi on 19/07/2023.
//

#include "JuegoView.h"

JuegoView::JuegoView() {
  JugadorView::init();
  j1 = new JugadorView();
  targetTexture.create(1280,720);
}

const sf::Sprite &JuegoView::getsprite() const {
  return sprite;
}

void JuegoView::actualizar() {
  j1->updateA();
  targetTexture.clear();
  targetTexture.draw(*j1);
  targetTexture.display();
  sprite.setTexture(targetTexture.getTexture());
}

JuegoView::~JuegoView() {
  delete j1;
}


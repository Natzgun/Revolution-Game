//
// Created by msumi on 19/07/2023.
//

#include "JuegoView.h"

JuegoView::JuegoView() {
  PersonajeView::init();
  ProyectilV::init();
  j1 = std::make_unique<JugadorView>();
  targetTexture.create(1280,720);
}

const sf::Sprite &JuegoView::getsprite() const {
  return sprite;
}

void JuegoView::actualizar() {
  j1->actualizar();
  targetTexture.clear();
  targetTexture.draw(*j1);
  targetTexture.display();
  sprite.setTexture(targetTexture.getTexture());
}

JuegoView::~JuegoView() {
  /*delete j1;
  for (int i = 0; i < proyectiles.size(); i++) {
    delete proyectiles[i];
  }*/
}

void JuegoView::handleJuegoEvents() {
  j1->handleMoveEvents();
}

bool JuegoView::j1_Lclick() {
  return j1->presionarLclick();
}

bool JuegoView::j1_Rclick() {
  return j1->presionarRclick();
}

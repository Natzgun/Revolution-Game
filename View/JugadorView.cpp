#include "JugadorView.h"

std::vector<sf::Texture> JugadorView::quieto = {};
std::vector<sf::Texture> JugadorView::moviendose = {};
std::vector<sf::Texture> JugadorView::disparando = {};
std::vector<sf::Texture> JugadorView::lanzando = {};
std::vector<sf::Texture> JugadorView::piernas = {};

JugadorView::JugadorView(){
  this->animationP = new Animation(&piernas);
  this->animationT = new Animation(&quieto);
}

void JugadorView::updateA() {
  this->animationP->animar();
  this->animationT->animar();
}

sf::Sprite &JugadorView::getSprite() const {
  return this->animationP->getSprite();
}

void JugadorView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(animationP->getSprite(), states);
  target.draw(animationT->getSprite(), states);
}

void JugadorView::init() {
  moviendose = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkSilencer_");
  disparando = Animation::cargarImagenes(3,"../Resources/Player/sprPAttackSilencer_");
  lanzando = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkThrow_");
  piernas = Animation::cargarImagenes(16,"../Resources/Player/sprBikerLegs_");
  quieto = Animation::cargarImagenes(3,"../Resources/Player/sprPPickup_");
}

void JugadorView::setPosicion(float x, float y) const {
  animationP->getSprite().setPosition(x,y);
  animationT->getSprite().setPosition(x,y);
}

JugadorView::~JugadorView() {
  delete animationP;
  delete animationT;
}

/*void JugadorView::draw() {
  sprite.setPosition(position);
  window.draw(sprite);
}*/

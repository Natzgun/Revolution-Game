#include "PersonajeView.h"
#include <iostream>

std::vector<sf::Texture> PersonajeView::quieto = {};
std::vector<sf::Texture> PersonajeView::moviendose = {};
std::vector<sf::Texture> PersonajeView::disparando = {};
std::vector<sf::Texture> PersonajeView::lanzando = {};
std::vector<sf::Texture> PersonajeView::piernas = {};
std::vector<sf::Texture> PersonajeView::recogiendo = {};

PersonajeView::PersonajeView(){
  up = false;
  down = false;
  right = false;
  left = false;
  estado = PersonajeEstado::Quieto;
  arma = PersonajeEstado::Desarmado;
  animationP = std::make_unique<Animation>(&piernas);
  animationT = std::make_unique<Animation>(&quieto);
  animationP->getSprite().setOrigin(animationP->getSprite().getLocalBounds().width / 2, animationP->getSprite().getLocalBounds().height / 2);
  animationT->getSprite().setOrigin(animationT->getSprite().getLocalBounds().width / 3, animationT->getSprite().getLocalBounds().height / 2);
}

void PersonajeView::actualizar() {
  animar();
}

void PersonajeView::animar(){
  animationP->animar();
  animationT->animar();
}

void PersonajeView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(animationP->getSprite(), states);
  target.draw(animationT->getSprite(), states);
}

void PersonajeView::init() {
  quieto = Animation::cargarImagenes(1,"../Resources/Player/sprPWalkSilencer_");
  moviendose = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkSilencer_");
  disparando = Animation::cargarImagenes(3,"../Resources/Player/sprPAttackSilencer_");
  lanzando = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkThrow_");
  piernas = Animation::cargarImagenes(16,"../Resources/Player/sprBikerLegs_");
  recogiendo = Animation::cargarImagenes(3,"../Resources/Player/sprPPickup_");
}

void PersonajeView::setPosicion(Vector2d<float> pos_) const {
  animationP->getSprite().setPosition(pos_.x,pos_.y);
  animationT->getSprite().setPosition(pos_.x,pos_.y);
}

PersonajeView::~PersonajeView() = default;

void PersonajeView::setDireccion(Vector2d<float> movimiento, Vector2d<float> mirada) const {
  Animation::setDir(animationP->getSprite(),movimiento.x,movimiento.y);
  Animation::setDir(animationT->getSprite(),mirada.x,mirada.y);
}

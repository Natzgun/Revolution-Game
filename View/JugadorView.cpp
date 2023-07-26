#include "JugadorView.h"
#include <iostream>

std::array<char,5> estados = {'q','m','d','l','r'};
std::vector<sf::Texture> JugadorView::quieto = Animation::cargarImagenes(1,"../Resources/Player/sprPWalkSilencer_");;
std::vector<sf::Texture> JugadorView::moviendose = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkSilencer_");
std::vector<sf::Texture> JugadorView::disparando = Animation::cargarImagenes(3,"../Resources/Player/sprPAttackSilencer_");
std::vector<sf::Texture> JugadorView::lanzando = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkThrow_");
std::vector<sf::Texture> JugadorView::piernas = Animation::cargarImagenes(16,"../Resources/Player/sprBikerLegs_");
std::vector<sf::Texture> JugadorView::recogiendo = Animation::cargarImagenes(3,"../Resources/Player/sprPPickup_");

JugadorView::JugadorView(){
  up = false;
  down = false;
  right = false;
  left = false;
  estado = 0;
  animationP = new Animation(&piernas);
  animationT = new Animation(&quieto);
  animationP->getSprite().setOrigin(animationP->getSprite().getLocalBounds().width / 2, animationP->getSprite().getLocalBounds().height / 2);
  animationT->getSprite().setOrigin(animationT->getSprite().getLocalBounds().width / 2, animationT->getSprite().getLocalBounds().height / 2);
}

void JugadorView::actualizar(sf::Vector2f pos_, sf::Vector2i dir_) {
  manejarEventos();
  animar();
  setPosicion(pos_.x, pos_.y);
  setDireccion(dir_.x, dir_.y);
}

void JugadorView::animar(){
  animationP->animar();
  if(animationT->animar()){
    if(lclick){lclick = false;}
    else if(rclick){rclick = false;}
    animationT->setTetures(&quieto);
  }
}

sf::Sprite &JugadorView::getSprite() const {
  return this->animationP->getSprite();
}

void JugadorView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(animationP->getSprite(), states);
  target.draw(animationT->getSprite(), states);
}

void JugadorView::init() {
  quieto = Animation::cargarImagenes(1,"../Resources/Player/sprPWalkSilencer_");
  moviendose = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkSilencer_");
  disparando = Animation::cargarImagenes(3,"../Resources/Player/sprPAttackSilencer_");
  lanzando = Animation::cargarImagenes(8,"../Resources/Player/sprPWalkThrow_");
  piernas = Animation::cargarImagenes(16,"../Resources/Player/sprBikerLegs_");
  recogiendo = Animation::cargarImagenes(3,"../Resources/Player/sprPPickup_");
}

void JugadorView::setPosicion(float x, float y) const {
  animationP->getSprite().setPosition(x,y);
  animationT->getSprite().setPosition(x,y);
}

JugadorView::~JugadorView() {
  delete animationP;
  delete animationT;
}

void JugadorView::manejarEventos() {
  //mover en eje y
  if (!down && sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    up = true;
  else if (!up && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    down = true;
  else {up = false; down = false;}
  //mover en eje x
  if (!right && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    left = true;
  else if (!left && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    right = true;
  else {left = false; right = false;}
  //disparar
  if(!(lclick || rclick)) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      lclick = true;
      animationT->setTetures(&disparando);
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      rclick = true;
      animationT->setTetures(&lanzando);
    }
  }
}

void JugadorView::setDireccion(float x, float y) {
  float p_x = static_cast<float>(left)*-1 + static_cast<float>(right);
  float p_y = static_cast<float>(up)*-1 + static_cast<float>(down);
  Animation::setDir(animationP->getSprite(),p_x,p_y);
  Animation::setDir(animationT->getSprite(),x,y);
}

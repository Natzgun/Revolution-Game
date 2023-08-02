#include "JugadorView.h"
#include <iostream>

JugadorView::JugadorView(){
  lclick = false;
  rclick = false;
  /*animationP->getSprite().setScale(2.0f, 2.0f);
  animationT->getSprite().setScale(2.0f, 2.0f);*/
}

void JugadorView::actualizar(sf::Vector2f pos_, sf::Vector2i dir_) {
  handleKeyEvents();
  animar();
  Vector2d<float> posi(pos_.x, pos_.y);
  float p_x = static_cast<float>(left)*-1 + static_cast<float>(right);
  float p_y = static_cast<float>(up)*-1 + static_cast<float>(down);
  Vector2d<float> mir(static_cast<float>(dir_.x), static_cast<float>(dir_.y));
  Vector2d<float> mov(p_x,p_y);
  setPosicion(posi);
  setDireccion(mov, mir);
}

void JugadorView::animar(){
  animationP->animar();
  if(animationT->animar()){
    if(lclick){lclick = false;}
    else if(rclick){rclick = false;}
    animationT->setTetures(&quieto);
  }
}

void JugadorView::handleKeyEvents() {
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

bool JugadorView::presionarLclick() {
  if(!(lclick || rclick)) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      lclick = true;
      animationT->setTetures(&disparando);
      return true;
    }
  }
  return false;
}

bool JugadorView::presionarRclick() {
  if(!(lclick || rclick)) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      rclick = true;
      animationT->setTetures(&lanzando);
      return true;
    }
  }
  return false;
}

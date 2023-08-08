#include "JugadorView.h"
#include <iostream>

JugadorView::JugadorView(){
  lclick = false;
  rclick = false;
  /*animationP->getSprite().setScale(2.0f, 2.0f);
  animationT->getSprite().setScale(2.0f, 2.0f);*/
}

void JugadorView::actualizar() {
  moveDir.x = static_cast<float>(left)*-1 + static_cast<float>(right);
  moveDir.y = static_cast<float>(up)*-1 + static_cast<float>(down);;
  animar();
}

void JugadorView::animar(){
  animationP->animar();
  if(animationT->animar()){
    if(lclick){lclick = false; estado = PersonajeEstado::Quieto;}
    else if(rclick){rclick = false; estado = PersonajeEstado::Quieto;}
    animationT->setTetures(&quieto);
  }
}

void JugadorView::handleMoveEvents() {
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
  /*if(!(lclick || rclick)) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      lclick = true;
      animationT->setTetures(&disparando);
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
      rclick = true;
      animationT->setTetures(&lanzando);
    }
  }*/
}

bool JugadorView::presionarLclick() {
  if(!(lclick || rclick)) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      lclick = true;
      animationT->setTetures(&disparando);
      estado = PersonajeEstado::Disparando;
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
      estado = PersonajeEstado::Lanzando;
      return true;
    }
  }
  return false;
}

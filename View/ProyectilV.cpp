#include "ProyectilV.h"

sf::Texture ProyectilV::normal = {};
sf::Texture ProyectilV::especial = {};

void ProyectilV::init() {
  normal = Animation::cargarImagen("../Resources/Otros/sprSoup_0.png");
  especial = Animation::cargarImagen("../Resources/Otros/sprSoup_0.png");
}

ProyectilV::ProyectilV() {
}

void ProyectilV::setPosicion(float x, float y) {
  sprite.setPosition(x,y);
}

void ProyectilV::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(sprite, states);
}

void ProyectilV::updateA() {
}

sf::Sprite &ProyectilV::getSprite() {
  return sprite;
}

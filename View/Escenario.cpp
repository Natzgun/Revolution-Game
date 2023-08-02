//
// Created by natzgun on 1/08/23.
//

#include "Escenario.h"

Escenario::Escenario() {
  setBackground();
  camara.setSize(sf::Vector2f(1280.0f, 720.0f)); // Tamaño de la ventana
  //camara.setCenter(camara.getSize() / 2.0f);
}

void Escenario::setBackground() {
  if (!backgroundTexture.loadFromFile("../Resources/bg-miami.jpg"))
  {
    // Error al cargar la imagen de fondo
    throw std::runtime_error("No se pudo cargar la imagen");
  }
  backgroundSprite.setTexture(backgroundTexture);
}

sf::Sprite &Escenario::getSprite() {
  return backgroundSprite;
}

Escenario::~Escenario() {

}

void Escenario::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.setView(camara);
  target.draw(backgroundSprite, states);
}

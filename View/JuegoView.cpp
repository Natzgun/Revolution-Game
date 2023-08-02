//
// Created by msumi on 19/07/2023.
//

#include "JuegoView.h"

JuegoView::JuegoView() {
  //JugadorView::init();
  ProyectilV::init();
  initMusic();
  j1 = std::make_unique<JugadorView>();
  e1 = new Escenario();
  targetTexture.create(1280,720);
}

const sf::Sprite &JuegoView::getsprite() const {
  return sprite;
}

void JuegoView::actualizar(sf::Vector2f pos_, sf::Vector2i dir_) {
  j1->actualizar(pos_, dir_);

  sf::Vector2f jugadorPosition = pos_;
  sf::Vector2f vistaCenter = e1->camara.getCenter();
  vistaCenter.x = jugadorPosition.x; // Centrar la vista en la posición X del jugador
  vistaCenter.y = jugadorPosition.y; // Centrar la vista en la posición Y del jugador
  e1->camara.setCenter(vistaCenter);

  targetTexture.clear();
 // targetTexture.setView(e1->camara);
  targetTexture.draw(*e1);
  targetTexture.draw(*j1);
  targetTexture.display();
  sprite.setTexture(targetTexture.getTexture());
}

JuegoView::~JuegoView() {
  delete e1;
  /*delete j1;
  for (int i = 0; i < proyectiles.size(); i++) {
    delete proyectiles[i];
  }*/
}

sf::Music &JuegoView::getMusic() {
  return musicaGame;
}

void JuegoView::initMusic() {
  if (!musicaGame.openFromFile("../Resources/Gamemusic.ogg"))
    throw std::runtime_error("No se pudo cargar la musica");
  musicaGame.setVolume(100);
  musicaGame.setVolume(musicaGame.getVolume() / 2);
  musicaGame.stop();
}

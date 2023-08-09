//
// Created by msumi on 19/07/2023.
//

#include "JuegoView.h"

JuegoView::JuegoView() {
  PersonajeView::init();
  ProyectilV::init();
  initMusic();
  j1 = std::make_unique<JugadorView>();
  e1 = new Escenario();
  targetTexture.create(1280,720);
}

const sf::Sprite &JuegoView::getsprite() const {
  return sprite;
}

void JuegoView::actualizar() {
  j1->actualizar();
  targetTexture.clear();
 // targetTexture.setView(e1->camara);
  targetTexture.draw(*e1);
  targetTexture.draw(*j1);
  targetTexture.display();
  sprite.setTexture(targetTexture.getTexture());
}

JuegoView::~JuegoView() {
  delete e1;
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

#include "Animation.h"

Animation::Animation(): frameTime(0.1f), clock(), sprite() {
}

Animation::Animation(std::vector<sf::Texture>* _frames): frameTime(0.1f), clock(), sprite() {
  // Cargar las imágenes y configurar los sprites
  setTetures(_frames);
}

/*bool Animation::animar() {
  if (clock.getElapsedTime().asSeconds() > frameTime)
  {
    // Cambiar al siguiente frame
    currentFrame = (currentFrame + 1) % numFrames;
    sprite.setTexture((*frames)[currentFrame]);
    clock.restart();
  }
  return true;
}*/
bool Animation::animar() {
  //retornara true cuando un ciclo de animacion se haya completado
  bool completado = false;
  if (clock.getElapsedTime().asSeconds() > frameTime)
  {
    // Cambiar al siguiente frame
    currentFrame++;
    if(currentFrame >= numFrames){
      currentFrame = 0;
      completado = true;
    }
    sprite.setTexture((*frames)[currentFrame]);
    clock.restart();
  }
  return completado;
}
sf::Sprite &Animation::getSprite() {
  return sprite;
}

void Animation::setTetures(std::vector<sf::Texture> *_frames){
  frames =_frames;
  numFrames = frames->size();
  currentFrame = 0;
  clock.restart();
  sprite.setTexture((*frames)[currentFrame]);
}

std::vector<sf::Texture> Animation::cargarImagenes(const int& n, const std::string& path) {
  std::vector<sf::Texture> textures;
  textures.reserve(n);
  for (int i = 0; i < n; i++){
    textures.push_back(cargarImagen(path + std::to_string(i) + ".png"));
  }
  return std::move(textures);
}

sf::Texture Animation::cargarImagen(const std::string& path) {
  sf::Texture tx;
  tx.loadFromFile(path);
  return tx;
}

void Animation::setPos(sf::Sprite& sp, const float & x, const float & y) {
  sp.setPosition(x,y);
}

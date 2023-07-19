#include "Animation.h"

Animation::Animation(std::vector<sf::Texture>* _frames): frameTime(0.1f), clock(), sprite() {
  // Cargar las imágenes y configurar los sprites
  setTetures(_frames);
}

void Animation::animar() {
  if (clock.getElapsedTime().asSeconds() > frameTime)
  {
    // Cambiar al siguiente frame
    currentFrame = (currentFrame + 1) % numFrames;
    sprite.setTexture((*frames)[currentFrame]);
    clock.restart();
  }
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

std::vector<sf::Texture> Animation::cargarImagenes(int n, std::string path) {
  std::vector<sf::Texture> textures;
  for (int i = 0; i < n; i++)
  {
    std::string filename = path + std::to_string(i) + ".png";
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
    {
      // Manejo de error en caso de que no se pueda cargar la imagen
      throw std::runtime_error("No se pudo cargar la imagen: " + filename);
    }
    textures.push_back(texture);
  }
  return std::move(textures);
}
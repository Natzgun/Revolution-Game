#include "Animation.h"

Animation::Animation(int numFrames, float frameTime, std::string folderPath): numFrames(numFrames), frameTime(frameTime), currentFrame(0), clock(), sprite() {
  // Cargar las imágenes y configurar los sprites
  for (int i = 0; i < numFrames; i++)
  {
    std::string filename = folderPath + "sprPAttackAxe_" + std::to_string(i) + ".png";
    sf::Texture frameTexture;
    if (!frameTexture.loadFromFile(filename))
    {
      // Manejo de error en caso de que no se pueda cargar la imagen
      throw std::runtime_error("No se pudo cargar la imagen: " + filename);
    }
    frames.push_back(frameTexture);
  }
  sprite.setTexture(frames[currentFrame]);
}

void Animation::animar() {
  if (clock.getElapsedTime().asSeconds() > frameTime)
  {
    // Cambiar al siguiente frame
    currentFrame = (currentFrame + 1) % numFrames;
    sprite.setTexture(frames[currentFrame]);
    clock.restart();
  }
}

sf::Sprite &Animation::getSprite() {
  return sprite;
}

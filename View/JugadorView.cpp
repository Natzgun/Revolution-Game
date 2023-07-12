
#include "JugadorView.h"

JugadorView::JugadorView(int numFrames, float frameTime): numFrames(numFrames), frameTime(frameTime), currentFrame(0), clock(), sprite() {
  // Ruta de la carpeta donde se encuentran las imágenes
  std::string folderPath = "../Resources/Player/Axe/";

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

void JugadorView::updateA() {
  //std::cout << "Aqui esta entrando" << std::endl;
  // std::cout << clock.getElapsedTime().asSeconds()*120 << std::endl;

  if (clock.getElapsedTime().asSeconds() > frameTime)
  {
    //std::cout << "Estoy dentro" << std::endl;

    // Cambiar al siguiente frame
    currentFrame = (currentFrame + 1) % numFrames;
    sprite.setTexture(frames[currentFrame]);
    clock.restart();

  }
}

sf::Sprite &JugadorView::getSprite() {
  return sprite;
}

void JugadorView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(this->sprite, states);
}

/*void JugadorView::draw() {
  sprite.setPosition(position);
  window.draw(sprite);
}*/

#include "Render.h"

Render* Render::render = nullptr;

Render::Render(){
  targetTexture.create(1280,720);
}

Render *Render::GetInstance() {
  if(render == nullptr)
    render = new Render();
  return render;
}

void Render::cargarTexturas(const std::string& clave, const std::string& path, const int& cantidad) {
  std::vector<sf::Texture> vectorTexturas;
  for (int i = 0; i < cantidad; ++i) {
    sf::Texture textura;
    if (textura.loadFromFile(path + clave + std::to_string(i) + ".png")) {
      vectorTexturas.push_back(textura);
    }
  }
  texturas[clave] = vectorTexturas;
}

void Render::setPov(const Vector2d<float> &) {
}

void Render::dibujar(const std::string &clave, int indice, const Vector2d<float> &pos, const Vector2d<float> &dir) {
  sprite.setTexture(texturas[clave][indice]);
  sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
  sprite.setPosition(pos.x, pos.y);
  sprite.setRotation(std::atan2(dir.y, dir.x));
  targetTexture.draw(sprite);
}

sf::RenderTexture &Render::getTargetTexture() {
  return targetTexture;
}

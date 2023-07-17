
#include "JugadorView.h"

JugadorView::JugadorView(int numFrames, float frameTime, std::string folderPath){
  this->animation = new Animation(numFrames,frameTime,folderPath);
}

void JugadorView::updateA() {
  this->animation->animar();
}

sf::Sprite &JugadorView::getSprite() {
  return this->animation->getSprite();
}

void JugadorView::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(this->animation->getSprite(), states);
}

/*void JugadorView::draw() {
  sprite.setPosition(position);
  window.draw(sprite);
}*/

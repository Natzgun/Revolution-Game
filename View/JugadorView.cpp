#include "JugadorView.h"
#include <iostream>

JugadorView::JugadorView(){
  lclick = false;
  rclick = false;
  /*animationP->getSprite().setScale(2.0f, 2.0f);
  animationT->getSprite().setScale(2.0f, 2.0f);*/
}

void JugadorView::actualizar() {
  animar();
}

void JugadorView::animar(){
  animationP->animar();
  animationT->animar();
}

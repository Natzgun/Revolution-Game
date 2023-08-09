//
// Created by pickle on 09/08/23.
//

#include "AnimacionM.h"

AnimacionM::AnimacionM() {
  numFrames = 0;
  index = 0;
}
AnimacionM::AnimacionM(int tiempoMs_, int numFrames_) {
  tiempoMs = tiempoMs_;
  numFrames = numFrames_;
}

void AnimacionM::animar() {
  if(index+1 == numFrames)
    ciclo = true;
  else
    ciclo = false;
  index = (index+1)%numFrames;
}

// getters
int AnimacionM::getNumFrames() {
  return numFrames;
}

int AnimacionM::getIndex() {
  return index;
}

bool AnimacionM::getCiclo() {
  return ciclo;
}
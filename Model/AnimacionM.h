//
// Created by pickle on 09/08/23.
//

#ifndef REVOLUTION_GAME_ANIMACIONM_H
#define REVOLUTION_GAME_ANIMACIONM_H
#include <string>

class AnimacionM {
private:
  int tiempoMs;
  int numFrames;
  int index;
  bool ciclo;
public:
  AnimacionM();
  AnimacionM(int tiempoMs_,int numFrames_);
  ~AnimacionM() = default;
  void animar();
  int getNumFrames();
  int getIndex();
  bool getCiclo();

};


#endif //REVOLUTION_GAME_ANIMACIONM_H

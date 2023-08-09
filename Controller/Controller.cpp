#include "Controller.h"
#include <iostream>
#include <cmath>

namespace Ctlr {
  Controller::Controller() {
    ventanaAbierta = true;
    vista.setMediator(this);
    modelo.setMediator(this);
  }

  void Controller::ejecutar() {
    while (ventanaAbierta) {
      // Esto eh agreago para intercambiar en el menu
      if (vista.getKeyboard_Escape()) {
        vista.setStateB(false);
      }
      if(!vista.getSelectedButton()) {
        vista.drawMenuBG();
      } else {
        vista.draw();
      }
      //por arreglar comunicar tanto del view
      modelo.myJuego.p1->setArriba(vista.getJuego().j1->up);
      modelo.myJuego.p1->setAbajo(vista.getJuego().j1->down);
      modelo.myJuego.p1->setIzquierda(vista.getJuego().j1->left);
      modelo.myJuego.p1->setDerecha(vista.getJuego().j1->right);

      modelo.actualizar();
      vista.actualizar();

      vista.handleWindowEvents();
    }
  }

  void Controller::reactonP1Lclick() {
    //modelo.reactonLclick();
  }

  void Controller::reactonP1Rclick() {
    //modelo.reactonRclick();
  }

  void Controller::reactonClose() {
    ventanaAbierta = false;
  }
}

#include "Controller.h"
#include <iostream>
#include <cmath>
#include "../Model/GameWorld.h"

namespace Ctlr {
  Controller::Controller() {
    ventanaAbierta = true;
    vista.setMediator(this);
    modelo = std::make_unique<GameWorld>();
    modelo->setMediator(this);
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
      //Capturar eventos propios del estado menu o juego

      modelo->actualizar();
      vista.actualizar();
      //Eventos que modifican el sf::window
      vista.handleEvents();
    }
  }

  void Controller::reactonClose() {
    ventanaAbierta = false;
  }

  void Controller::notify(std::string& evento) {
    modelo->handleEvent(evento);
  }

  void Controller::sendMousePos(Vector2d<float> mouse) {
    modelo->setMousePos(mouse);
  }
}

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
      vista.handleWindowEvents();
    }
  }

  /*void Controller::toJuegoModel() {
    modelo.getJuego()->p1->setArriba(vista.getJuego().j1->up);
    modelo.getJuego()->p1->setAbajo(vista.getJuego().j1->down);
    modelo.getJuego()->p1->setIzquierda(vista.getJuego().j1->left);
    modelo.getJuego()->p1->setDerecha(vista.getJuego().j1->right);
    modelo.getJuego()->p1->setFacing(vista.getMousePosCenter());
    modelo.getJuego()->p1->estado = vista.getJuego().j1->estado;
  }*/

  /*void Controller::toJuegoView() {
    vista.getJuego().j1->setPosicion(modelo.getJuego()->p1->getPos());
    vista.getJuego().j1->setDireccion(vista.getJuego().j1->moveDir,vista.getMousePosCenter());
    for(auto&& i: modelo.myJuego.proyectiles){
      std::cout << i->getPosicion().x <<"_"<<i->getPosicion().y<<"  ";
    }
    std::cout<<std::endl;
  }*/

  void Controller::reactonP1Lclick() {
    modelo->handleEvent("lclick");
  }

  void Controller::reactonP1Rclick() {
    modelo->handleEvent("rclick");
  }

  void Controller::reactonClose() {
    ventanaAbierta = false;
  }
}

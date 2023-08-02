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
      //Capturar eventos propios del estado menu o juego
      vista.handleJuegoEvents();

      toJuegoModel();
      modelo.actualizar();
      toJuegoView();
      //modeltoView
      vista.actualizar();

      // Esto eh agreago para intercambiar en el menu
      if (vista.getKeyboard_Escape()) {
        vista.setStateB(false);
      }
      if(!vista.getSelectedButton()) {
        vista.drawMenuBG();
      } else {
        vista.draw();
      }
      //Eventos que modifican el sf::window
      vista.handleWindowEvents();
    }
  }

  void Controller::toJuegoModel() {
    modelo.myJuego.p1->setArriba(vista.getJuego().j1->up);
    modelo.myJuego.p1->setAbajo(vista.getJuego().j1->down);
    modelo.myJuego.p1->setIzquierda(vista.getJuego().j1->left);
    modelo.myJuego.p1->setDerecha(vista.getJuego().j1->right);
    //modelo.j1.mira
  }

  void Controller::toJuegoView() {
    vista.getJuego().j1->setPosicion(modelo.myJuego.p1->getPos());
    vista.getJuego().j1->setDireccion(vista.getJuego().j1->moveDir,vista.getMousePosCenter());
    /*for(auto&& i: modelo.myJuego.proyectiles){
      cout
    }*/
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

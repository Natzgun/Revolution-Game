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
      modelo.myJuego.p1->setArriba(vista.getJuego().j1->up);
      modelo.myJuego.p1->setAbajo(vista.getJuego().j1->down);
      modelo.myJuego.p1->setIzquierda(vista.getJuego().j1->left);
      modelo.myJuego.p1->setDerecha(vista.getJuego().j1->right);
      //enviar pos del mouse
      //enviar eventos rclic lclic al modelo
      toJuegoModel();
      sf::Vector2i dir = vista.getMousePos();
      dir -= vista.windowSize();
      modelo.actualizar();
      vista.actualizar(sf::Vector2f(modelo.myJuego.p1->getPos().x,modelo.myJuego.p1->getPos().y),dir);
      //std::cout <<vista.getJuego().j1->up<<"-"<<vista.getJuego().j1->left<<"-"<<vista.getJuego().j1->down<<"-"<<vista.getJuego().j1->right<< std::endl;
      vista.draw();
      vista.handleWindowEvents();
    }
  }

  void Controller::toJuegoModel() {
    modelo.myJuego.p1->setArriba(vista.getJuego().j1->up);
    modelo.myJuego.p1->setAbajo(vista.getJuego().j1->down);
    modelo.myJuego.p1->setIzquierda(vista.getJuego().j1->left);
    modelo.myJuego.p1->setDerecha(vista.getJuego().j1->right);
    /*if(!(vista.getJuego().j1->lclick || vista.getJuego().j1->rclick)) {
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        vista.getJuego().j1->lclick = true;
        //animationT->setTetures(&disparando);
        //modelo.myJuego.p1->setLclick(true);
      }
      else if(sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        vista.getJuego().j1->rclick = true;
        //animationT->setTetures(&lanzando);
        //modelo.myJuego.p1->setRclick(true);
      }
    }*/
  }

  void Controller::toJuegoView() {
    sf::Vector2f posj1 = sf::Vector2f(modelo.myJuego.p1->getPos().x,modelo.myJuego.p1->getPos().y);
    sf::Vector2i dirj1 = vista.getMousePos();
    dirj1 -= vista.windowSize();
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

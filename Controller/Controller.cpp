#include "Controller.h"
#include <iostream>
#include <cmath>

namespace Ctlr {

  Controller::Controller() {
  }

  void Controller::ejecutar() {
    while (vista.isRunning()) {
      // std::cout << "Running" << std::endl;
      // vista.actualizarVista();
      //vista.getClear();
      while (vista.getVentanaPollEvent()) {
        switch (vista.getEvent().type) {
          // El 0 = Closed
          case 0:
            std::cout << sf::Event::Closed << std::endl;
            vista.getCloseWindow();
            break;
        }
      }
      modelo.myJuego.p1->setArriba(vista.getJuego().j1->up);
      modelo.myJuego.p1->setAbajo(vista.getJuego().j1->down);
      modelo.myJuego.p1->setIzquierda(vista.getJuego().j1->left);
      modelo.myJuego.p1->setDerecha(vista.getJuego().j1->right);
      modelo.actualizar();
      sf::Vector2i dir = vista.getMousePos();
      vista.actualizar(sf::Vector2f(modelo.myJuego.p1->getPos().x,modelo.myJuego.p1->getPos().y),dir);
      std::cout <<vista.getJuego().j1->up<<"-"<<vista.getJuego().j1->left<<"-"<<vista.getJuego().j1->down<<"-"<<vista.getJuego().j1->right<< std::endl;
      vista.draw();
    }
  }
}

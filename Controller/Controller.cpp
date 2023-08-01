#include "Controller.h"
#include <iostream>

namespace Ctlr {

  Controller::Controller() {
  }

  void Controller::ejecutar() {
    int y = 0;
    int x = 0;

    while (vista.isRunning()) {
      // std::cout << "Running" << std::endl;
      // vista.actualizarVista();
      //vista.getClear();
      sf::Vector2f mousePosition;
      bool b = true;
      while (vista.getVentanaPollEvent()) {
        switch (vista.getEvent().type) {
          // El 0 = Closed
          case 0:
            std::cout << sf::Event::Closed << std::endl;
            vista.getCloseWindow();
            break;
          // El 9 = MoussePressed
          case 9:
            if (vista.getEvent().mouseButton.button == 0) {
              mousePosition = sf::Vector2f(sf::Mouse::getPosition(vista.getWindow()));
              vista.selectButton(mousePosition);
            }
            break;
        }
      }
      if (vista.getKeyboard_W()) {
        y -= 5;
        //vista.drawEsfera(50, x , y);
        //std::cout << "Tecla W presionada" << std::endl;
      }
      if (vista.getKeyboard_A()) {
        x -= 5;
        //vista.drawEsfera(50, x, y);
        //std::cout << "Tecla A presionada" << std::endl;
      }
      if (vista.getKeyboard_S()) {
        y += 5;
        //vista.drawEsfera(50, x, y);
        //std::cout << "Tecla S presionada" << std::endl;
      }
      if (vista.getKeyboard_D()) {
        x += 5;
        //vista.drawEsfera(50, x, y);
        //std::cout << "Tecla D presionada" << std::endl;
      }

      if (vista.getKeyboard_Escape()) {
        vista.setStateB(false);
      }

      if(!vista.getSelectedButton()) {
        vista.drawMenuBG();
      } else {
        vista.draw();
      }
      vista.getJuego().j1->setPosicion(x,y);
      vista.actualizar();
    }
  }
}

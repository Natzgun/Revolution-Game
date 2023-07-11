#include "Controller.h"
#include <iostream>

namespace Ctlr {

  Controller::Controller() {
  }

  void Controller::ejecutar() {
    int y = 1;
    int x = 1;

    while (vista.isRunning()) {
      // std::cout << "Running" << std::endl;
      // vista.actualizarVista();
      vista.getClear();
      while (vista.getVentanaPollEvent()) {
        switch (vista.getEvent().type) {
          // El 0 = Closed
          case 0:
            std::cout << sf::Event::Closed << std::endl;
            vista.getCloseWindow();
            break;
        }
      }
      if (vista.getKeyboard_W()) {
        y -= 5;
        //vista.drawEsfera(50, x , y);
        std::cout << "Tecla W presionada" << std::endl;
      }
      if (vista.getKeyboard_A()) {
        x -= 5;
        //vista.drawEsfera(50, x, y);
        std::cout << "Tecla A presionada" << std::endl;
      }
      if (vista.getKeyboard_S()) {
        y += 5;
        //vista.drawEsfera(50, x, y);
        std::cout << "Tecla S presionada" << std::endl;
      }
      if (vista.getKeyboard_D()) {
        x += 5;
        //vista.drawEsfera(50, x, y);
        std::cout << "Tecla D presionada" << std::endl;
      }
      // vista.initializeMenu();
      vista.drawJugador(x,y);
      // vista.drawEsfera(50, x, y);
      vista.getDisplay();
    }
  }

}

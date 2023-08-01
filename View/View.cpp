#include "View.h"

namespace Vw {

  View::View() {
    window.create(sf::VideoMode(1280, 720), "Ventana SFML");
    window.setFramerateLimit(60);
    JugadorView::init();
    MenuView::init();
    this->mainMenu = new MenuView();
    // this->jugadorPrincipal = new JugadorView();
    // this->mainMenu = new Menu();
  }
  bool View::isRunning() {
    return window.isOpen();
  }
  void View::getClear() {
    window.clear();
  }
  void View::getDisplay() {
    window.display();
  }
  void View::actualizar() {
    if (!getSelectedButton()) {
      mainMenu->actualizar();
    } else {
      juego.actualizar();
    }
  }
  sf::Event& View::getEvent() {
      return evento;
  }
  bool View::getVentanaPollEvent() {
      return window.pollEvent(getEvent());
  }
  void View::getCloseWindow() {
    window.close();
  }
  bool View::getKeyboard_W() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  }
  bool View::getKeyboard_A() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
  }
  bool View::getKeyboard_S() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  }
  bool View::getKeyboard_D() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
  }
  bool View::getEventTypeClose() {
    return sf::Event::Closed;
  }
  bool View::getKeyboard_Escape() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
  }
  /*void View::drawJugador(int x, int y) {
    jugadorPrincipal->setPosicion(x,y);
    jugadorPrincipal->updateA();
    window.draw(*jugadorPrincipal);
  }*/
  void View::drawMenuBG() {
    window.clear();
    window.draw(mainMenu->getSprite());
    window.display();
  }


  /*void View::initMenuMusic() {
    mainMenu->getMusic();
  }*/

  void View::draw() {
    window.clear();
    window.draw(juego.getsprite());
    window.display();
  }

  JuegoView &View::getJuego() {
    return juego;
  }

  void View::selectButton(const sf::Vector2f &mousePosition) {
    mainMenu->handleButtonClick(mousePosition);
  }

  sf::RenderWindow &View::getWindow() {
    return window;
  }

  bool View::getSelectedButton() {
    return mainMenu->getSelectionB();
  }

  void View::setStateB(bool s) {
    mainMenu->setSelectionB(s);
  }


};

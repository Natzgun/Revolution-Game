#include "View.h"
#include "../Controller/Controller.h"

namespace Vw {

  View::View() {
    window.create(sf::VideoMode(1280, 720), "Ventana SFML");
    window.setFramerateLimit(60);
    //JugadorView::init();
    this->mainMenu = new Menu();
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
  /////asjfdnaklsjfnkajsfn
  void View::actualizar(sf::Vector2f pos_, sf::Vector2i dir_) {
    //handleEvents();
    juego.actualizar(pos_, dir_);
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
  /*void View::drawJugador(int x, int y) {
    jugadorPrincipal->setPosicion(x,y);
    jugadorPrincipal->updateA();
    window.draw(*jugadorPrincipal);
  }*/
  void View::drawMenuBG() {
    window.draw(mainMenu->getSprite());
  }
  void View::initMenuMusic() {
    mainMenu->getMusic();
  }

  void View::draw() {
    window.clear();
    window.draw(juego.getsprite());
    window.display();
  }

  JuegoView &View::getJuego() {
    return juego;
  }

  sf::Vector2<int> View::getMousePos() {
    return sf::Mouse::getPosition(window);
  }

  sf::Vector2<int> View::windowSize(){
    sf::Vector2u win = window.getSize();
    sf::Vector2i v;
    v.x = win.x/2; v.y = win.y/2;
    return v;
  }

  void View::setMediator(Ctlr::Controller* mediator_) {
    mediator = std::shared_ptr<Ctlr::Controller>(mediator_);
  }
  void View::handleEvents() {
    while (window.pollEvent(evento)) {
      switch (evento.type) {
        // El 0 = Closed
        case 0:
          std::cout << sf::Event::Closed << std::endl;
          window.close();
          mediator->reactonClose();
          break;
      }
    }
  }
}

#include "View.h"
#include "../Controller/Controller.h"

namespace Vw {

  View::View() {
    fullscreen = false;
    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Revolution_Game", sf::Style::Fullscreen);
    window.create(sf::VideoMode(1280, 720), "Revolution_Game");
    window.setFramerateLimit(60);
    //JugadorView::init();
    juego = std::make_unique<JuegoView>();
    MenuView::init();
    //this->currentState = std::make_unique<MenuView>();
    this->mainMenu = new MenuView();
  }
  void View::actualizar() {
    //handleEvents();
    if (!getSelectedButton()) {
      mainMenu->actualizar();
    } else {
      juego->actualizar();
    }
  }

  /*void View::drawJugador(int x, int y) {
    jugadorPrincipal->setPosicion(x,y);
    jugadorPrincipal->updateA();
    window.draw(*jugadorPrincipal);
  }*/
  void View::drawMenuBG() {
    juego->getMusic().stop();
    window.clear();
    window.draw(mainMenu->getSprite());
    window.display();
  }

  void View::draw() {
    window.clear();
    window.draw(juego->getsprite());
    window.display();
  }

  JuegoView &View::getJuego() {
    return *juego;
  }

  sf::Vector2<int> View::getMousePos() {
    return sf::Mouse::getPosition(window);
  }

  void View::setMediator(Ctlr::Controller* mediator_) {
    mediatorRef = mediator_;
  }
  void View::handleWindowEvents() {
    sf::Vector2f mousePosition;
    while (window.pollEvent(evento)) {
      //Cerrar ventana
      if (evento.type == sf::Event::Closed) {
        window.close();
        mediatorRef->reactonClose();
      }
      //Cambiar modo de ventana fullscreen
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::F) {
        fullscreen = !fullscreen;
        if (fullscreen) {
          window.create(sf::VideoMode::getDesktopMode(), "Revolution_Game", sf::Style::Fullscreen);
        } else {
          window.create(sf::VideoMode(1280, 720), "Revolution_Game", sf::Style::Default);
        }
      }
      //Cambiar de Menuview a JuegoView
      else if (evento.type == sf::Event::MouseButtonPressed) {
        if (evento.mouseButton.button == 0 && !getSelectedButton()) {
          mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
          selectButton(mousePosition);
          mainMenu->getMusic().stop();
          juego->getMusic().play();
        }
      }
    }
  }

  bool View::getKeyboard_Escape() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape);
  }

  void View::selectButton(const sf::Vector2f &mousePosition) {
    mainMenu->handleButtonClick(mousePosition);
  }

  bool View::getSelectedButton() {
    return mainMenu->getSelectionB();
  }

  void View::setStateB(bool s) {
    mainMenu->setSelectionB(s);
  }

  View::~View() {
    delete mainMenu;
  }
}

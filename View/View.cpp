#include "View.h"
#include "../Controller/Controller.h"

namespace Vw {

  View::View() {
    fullscreen = false;
    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Revolution_Game", sf::Style::Fullscreen);
    window.create(sf::VideoMode(1280, 720), "Revolution_Game");
    window.setFramerateLimit(60);
    estado = std::make_unique<JuegoView>(&coladeEventos);
    MenuView::init();
    this->mainMenu = new MenuView();
  }

  void View::actualizar() {
    //handleEvents();
    if (!getSelectedButton()) {
      mainMenu->actualizar();
    } else {
    }
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
  void View::initMenuMusic() {
    mainMenu->getMusic();
  }

  void View::draw() {
    window.clear();
    window.display();
  }

  void View::setMediator(Ctlr::Controller* mediator_) {
    mediatorRef = mediator_;
  }

  void View::handleWindowEvents() {
    sf::Vector2f mousePosition;
    while (window.pollEvent(evento)) {
      if (evento.type == sf::Event::Closed) {
        window.close();
        mediatorRef->reactonClose();
      }
      else if (evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::F) {
        fullscreen = !fullscreen;
        if (fullscreen) {
          window.create(sf::VideoMode::getDesktopMode(), "Revolution_Game", sf::Style::Fullscreen);
        } else {
          window.create(sf::VideoMode(1280, 720), "Revolution_Game", sf::Style::Default);
        }
      }
      else if (evento.type == sf::Event::MouseButtonPressed) {
        if (evento.mouseButton.button == 0) {
          mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
          selectButton(mousePosition);
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

  void View::handleStateEvents() {
    while (!coladeEventos.empty()) {
      mediatorRef->notify(coladeEventos.front());
      coladeEventos.pop();
    }
  }

  void View::handleEvents() {
    mediatorRef->sendMousePos(estado->getMousePos(window));
    handleStateEvents();
    handleWindowEvents();
  }
}

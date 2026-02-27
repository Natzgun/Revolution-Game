#include "View.h"
#include "../Controller/Controller.h"
#include <optional>

namespace Vw {

  View::View() {
    fullscreen = false;
    //sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Revolution_Game", sf::Style::Fullscreen);
    window.create(sf::VideoMode({1280, 720}), "Revolution_Game");
    window.setFramerateLimit(60);
    //JugadorView::init();
    juego = std::make_unique<JuegoView>();
    MenuView::init();
    //this->currentState = std::make_unique<MenuView>();
    this->mainMenu = new MenuView();
  }
  void View::actualizar(sf::Vector2f pos_, sf::Vector2i dir_) {
    //handleEvents();
    if (!getSelectedButton()) {
      mainMenu->actualizar();
    } else {
      juego->actualizar(pos_, dir_);
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
  void View::initMenuMusic() {
    mainMenu->getMusic();
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

  sf::Vector2<int> View::windowSize(){
    sf::Vector2u win = window.getSize();
    sf::Vector2i v;
    v.x = win.x/2; v.y = win.y/2;
    return v;
  }

  void View::setMediator(Ctlr::Controller* mediator_) {
    mediatorRef = mediator_;
  }
  void View::handleWindowEvents() {
    sf::Vector2f mousePosition;
    while (std::optional<sf::Event> event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
        mediatorRef->reactonClose();
      }
      else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->code == sf::Keyboard::Key::F) {
          fullscreen = !fullscreen;
          if (fullscreen) {
            window.create(sf::VideoMode::getDesktopMode(), "Revolution_Game", sf::State::Fullscreen);
          } else {
            window.create(sf::VideoMode({1280, 720}), "Revolution_Game");
          }
        }
      }
      else if (const auto* mouseButtonPressed = event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseButtonPressed->button == sf::Mouse::Button::Left && getSelectedButton() == false) {
          mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
          selectButton(mousePosition);
          mainMenu->getMusic().stop();
          juego->getMusic().play();
        }
      }
    }
  }

  bool View::getKeyboard_Escape() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape);
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

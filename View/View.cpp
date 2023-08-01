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
    mainMenu = std::make_unique<Menu>();
  }
  void View::actualizar(sf::Vector2f pos_, sf::Vector2i dir_) {
    //handleEvents();
    juego->actualizar(pos_, dir_);
  }
  sf::Event& View::getEvent() {
      return evento;
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
  void View::handleEvents() {
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
    }
  }

  View::~View() {
  }
}

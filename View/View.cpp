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
  sf::Event& View::getEvent() {
      return evento;
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
    window.draw(juego->getsprite());
    window.display();
  }

  JuegoView &View::getJuego() {
    return *juego;
  }

  Vector2d<float> View::getMousePosCenter() {
    float xx = sf::Mouse::getPosition(window).x - (window.getSize().x/2.0);
    float yy = sf::Mouse::getPosition(window).y - (window.getSize().y/2.0);
    Vector2d<float> mousePos_(xx,yy);
    return mousePos_;
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

  void View::handleJuegoEvents() {
    juego->handleJuegoEvents();
    if(juego->j1_Lclick()){mediatorRef->reactonP1Lclick();}
    if(juego->j1_Rclick()){mediatorRef->reactonP1Rclick();}
  }

  /*void View::handleJ1Events() {
    juego->
  }*/
}

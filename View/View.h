#ifndef MVC_ARCHITECTURE_SFML_VIEW_H
#define MVC_ARCHITECTURE_SFML_VIEW_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "JugadorView.h"
#include "JuegoView.h"
#include "Menu.h"
#include <memory>

namespace Ctlr {
  class Controller;
}

namespace Vw {
  class View {
  private:
    bool fullscreen;
    sf::RenderWindow window;
    sf::Event evento;
    std::unique_ptr<JuegoView> juego;
    std::unique_ptr<Menu> mainMenu;
    Ctlr::Controller* mediatorRef;
  public:
    View();
    ~View();
    void setMediator(Ctlr::Controller* mediator_);
    // No se deben llamarse gets
    sf::Event& getEvent();
    sf::Vector2<int> windowSize();
    void handleWindowEvents();
    void handleJ1Events();
    JuegoView &getJuego();
    void actualizar(sf::Vector2f, sf::Vector2i);
    void draw();
    // Keyboard functions
    sf::Vector2<int> getMousePos();

    void initMenuMusic();
    void drawMenuBG();

    // Cargar el jugador
    void drawJugador(int, int);
    // void updateJugador();
  };
}

#endif //MVC_ARCHITECTURE_SFML_VIEW_H

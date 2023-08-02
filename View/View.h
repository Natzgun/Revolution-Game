#ifndef MVC_ARCHITECTURE_SFML_VIEW_H
#define MVC_ARCHITECTURE_SFML_VIEW_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "JugadorView.h"
#include "JuegoView.h"
#include "MenuView.h"
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
    MenuView* mainMenu;
    Ctlr::Controller* mediatorRef;
  public:
    View();
    ~View();
    void setMediator(Ctlr::Controller* mediator_);
    // No se deben llamarse gets
    sf::Event& getEvent();
    sf::Vector2<int> windowSize();
    void handleWindowEvents();
    void handleJuegoEvents();
    JuegoView &getJuego();
    void actualizar();
    void draw();
    // Keyboard functions
    Vector2d<float> getMousePosCenter();

    void initMenuMusic();
    void drawMenuBG();
    bool getKeyboard_Escape();
    void selectButton(const sf::Vector2f &mousePosition);
    bool getSelectedButton();
    void setStateB(bool);

    // Cargar el jugador
    // void updateJugador();
  };
}

#endif //MVC_ARCHITECTURE_SFML_VIEW_H

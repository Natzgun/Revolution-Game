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
    sf::RenderWindow window;
    sf::Event evento;
    JuegoView juego;
    Menu* mainMenu;
    std::shared_ptr<Ctlr::Controller> mediator;
  public:
    View();
    void setMediator(Ctlr::Controller* mediator_);
    bool isRunning();
    // No se deben llamarse gets
    sf::Event& getEvent();
    sf::Vector2<int> windowSize();
    bool getVentanaPollEvent();
    void handleEvents();
    void getCloseWindow();
    JuegoView &getJuego();
    void getDisplay();
    void getClear();
    void actualizar(sf::Vector2f, sf::Vector2i);
    void draw();
    bool getEventTypeClose();
    // Keyboard functions
    sf::Vector2<int> getMousePos();
    bool getKeyboard_W();
    bool getKeyboard_A();
    bool getKeyboard_S();
    bool getKeyboard_D();

    void initMenuMusic();
    void drawMenuBG();
    // Cargar el jugador
    void drawJugador(int, int);
    // void updateJugador();

  };
}

#endif //MVC_ARCHITECTURE_SFML_VIEW_H

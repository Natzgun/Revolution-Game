#ifndef MVC_ARCHITECTURE_SFML_VIEW_H
#define MVC_ARCHITECTURE_SFML_VIEW_H

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "JugadorView.h"
#include "JuegoView.h"
#include "Menu.h"
#include "MenuView.h"

namespace Vw {
  class View {
  private:
    sf::RenderWindow window;
    sf::Event evento;
    JuegoView juego;
    MenuView* mainMenu;
//    bool isSelected;
    // JugadorView* jugadorPrincipal;
    // Menu* mainMenu;
  public:
    View();
    bool isRunning();
    // No se deben llamarse gets
    sf::Event& getEvent();
    sf::RenderWindow& getWindow();
    bool getVentanaPollEvent();
    void getCloseWindow();
    JuegoView &getJuego();
    void getDisplay();
    void getClear();
    void actualizar();
    void draw();
    bool getEventTypeClose();
    // Keyboard functions
    bool getKeyboard_W();
    bool getKeyboard_A();
    bool getKeyboard_S();
    bool getKeyboard_D();

    //void initMenuMusic();
    void drawMenuBG();

    void selectButton(const sf::Vector2f &mousePosition);
    bool getSelectedButton();
    void setStateB(bool);
    /*void setSelectionB(bool);
    bool &getSelectionB();*/
    // Cargar el jugador
    //void drawJugador(int, int);
    // void updateJugador();

  };
}

#endif //MVC_ARCHITECTURE_SFML_VIEW_H

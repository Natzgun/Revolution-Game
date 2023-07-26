//
// Created by alonso on 7/25/23.
//

#ifndef REVOLUTION_GAME_MAINMENU_H
#define REVOLUTION_GAME_MAINMENU_H


class MainMenu {
  private:
    int looking;
    // 0 = startJuego
    // 1 = modePlayer
    // 2 = chooseLevel
    // 3 = closeGame

    bool startJuego;
    bool modePlayer; //  true = 1 player
    // false = 2 player
    bool chooseLevel;
    bool closeGame;

    int lookingLevel;
    void actualizarLooking(int&,int);
    void doChooseLevel();
    void doMainMenu();
  public:
    bool enterKey;
    bool upKey;
    bool downKey;
    MainMenu();
    void actualizar();


};


#endif //REVOLUTION_GAME_MAINMENU_H

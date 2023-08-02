//
// Created by alonso on 7/25/23.
//

#include "MainMenu.h"
#include "Juego.h"

MainMenu::MainMenu() {
  looking = 0;
  enterKey = false;
  upKey = false;
  downKey = false;

  startJuego = false;
  modePlayer = false;
  chooseLevel = false;
  closeGame = false;
}

void MainMenu::actualizar() {

  if (chooseLevel){

    actualizarLooking(looking, 5);
    doChooseLevel();
    enterKey = false;

  }
  else{
    // Cambiando looking
    actualizarLooking(looking,4);
    // Viendo casos de looking
    doMainMenu();
    enterKey = false;
  }
}

void MainMenu::actualizarLooking(int& l, int rango) {
  l= (l+rango)% rango;
  if (downKey) {
    l++;
    downKey = false;
  }
  if (upKey){
    l--;
    upKey = false;
  }
}

void MainMenu::doChooseLevel() {
  if(enterKey) {

    switch (looking) {
      case 0:
        cout << "eligiendo level 1 ";
        Juego::pathNivel += "1.csv";
        break;
      case 1:
        cout << "eligiendo level 2 ";
        Juego::pathNivel += "2.csv";
        break;
      case 2:
        cout << "eligiendo level 3 ";
        Juego::pathNivel += "3.csv";
        break;
      case 3:
        cout << "eligiendo level 4 ";
        Juego::pathNivel += "4.csv";
        break;
      case 4:
        cout << "eligiendo level 5 ";
        Juego::pathNivel += "5.csv";
        break;
      default:
        Juego::pathNivel += "1.csv";
    }

  }
}

void MainMenu::doMainMenu() {

  if(enterKey) {

    switch (looking) {
      case 0:
        cout << "mirando a starJuego ";
        startJuego = true;
        break;
      case 1: // toggle
        cout << "mirando a modePlayer ";
        if (modePlayer)
          modePlayer = false;
        else
          modePlayer = true;
        break;
      case 2:
        cout << "mirando a chooseLevel ";
        chooseLevel = true;
        break;
      case 3:
        cout << "mirando a closeGame ";
        closeGame = true;
        break;
    }

  }

}

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
  if (downKey) {
    looking++;
    looking = looking % 4;
    downKey = false;
  }
  if (upKey){
    looking --;
    looking = (looking+4)% 4;
    upKey = false;
  }

  switch (looking) {
    case 0:
      cout<<"mirando a starJuego ";
      if(enterKey)
        startJuego = true;
      break;
    case 1: // toggle
      cout<<"mirando a modePlayer ";
      if(enterKey){
        if(modePlayer)
          modePlayer = false;
        else
          modePlayer = true;
      }
      break;
    case 2:
      cout<<"mirando a chooseLevel ";
      if(enterKey)
        chooseLevel = true;
      break;
    case 3:
      cout<<"mirando a closeGame ";
      if(enterKey)
        closeGame = true;
      break;
  }
  enterKey = false;

  if (chooseLevel){
    switch (level) {
      case 0:
        cout<<"eligiendo level 1 ";
        Juego::pathNivel ="../Resources/Niveles/Nivel-1.csv";
        break;
      case 1:
        cout<<"eligiendo level 2 ";
        Juego::pathNivel ="../Resources/Niveles/Nivel-2.csv";
        break;
      case 2:
        cout<<"eligiendo level 3 ";
        Juego::pathNivel ="../Resources/Niveles/Nivel-3.csv";
        break;
      case 3:
        cout<<"eligiendo level 4 ";
        Juego::pathNivel ="../Resources/Niveles/Nivel-4.csv";
        break;
      case 4:
        cout<<"eligiendo level 5 ";
        Juego::pathNivel ="../Resources/Niveles/Nivel-5.csv";
        break;
      default:
        Juego::pathNivel ="../Resources/Niveles/Nivel-1.csv";
    }
  }
}

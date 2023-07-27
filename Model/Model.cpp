#include "Model.h"

Mdl::Model::Model() {
    myJuego = nullptr;
    myMenu = new MainMenu();
}
void Mdl::Model::actualizar() {
  if (myMenu->startJuego && myJuego == nullptr)
    myJuego=new Juego();
  myMenu->actualizar();
}

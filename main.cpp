#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Model/Model.h"
#include "View/View.h"
#include "Controller/Controller.h"

int main() {
  Mdl::Model modelo;
  modelo.myJuego.p1->mostrar();
  modelo.myJuego.p1->setDerecha(true);
  modelo.actualizar();
  modelo.myJuego.p1->mostrar();
  Ctlr::Controller controlador;
  controlador.ejecutar();
  return 0;
}
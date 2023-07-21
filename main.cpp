#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Model/Model.h"
#include "View/View.h"
#include "Controller/Controller.h"

int main() {

  Mdl::Model modelo;
  modelo.myJuego.p1->imprimir();
  modelo.myJuego.p1->setDerecha(true);
  modelo.actualizar();
  modelo.myJuego.p1->imprimir();
  Ctlr::Controller controlador;
  controlador.ejecutar();
  Juego miJuego;

  return 0;
}
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Model/Model.h"
#include "View/View.h"
#include "Controller/Controller.h"

#include "View/Render.h"

int main() {
  Ctlr::Controller controlador;
  controlador.ejecutar();
  return 0;
}
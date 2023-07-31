#ifndef MVC_ARCHITECTURE_SFML_CONTROLLER_H
#define MVC_ARCHITECTURE_SFML_CONTROLLER_H

// Archivo Controller.h
#pragma once
#include "../Model/Model.h"
#include "../View/View.h"

namespace Ctlr {
  class Controller {
  private:
    bool ventanaAbierta;
    Mdl::Model modelo;
    Vw::View vista;
  public:
    Controller();
    void ejecutar();
    void toJuegoModel();
    void toJuegoView();
    void reactonLclick();
    void reactonRclick();
    void reactonClose();
  };
};

#endif //MVC_ARCHITECTURE_SFML_CONTROLLER_H

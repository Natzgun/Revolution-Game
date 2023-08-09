#ifndef MVC_ARCHITECTURE_SFML_CONTROLLER_H
#define MVC_ARCHITECTURE_SFML_CONTROLLER_H

#pragma once
#include "../Model/Model.h"
#include "../View/View.h"

namespace Ctlr {
  class Controller {
  private:
    bool ventanaAbierta;
    std::unique_ptr<Mdl::Model> modelo;
    Vw::View vista;
  public:
    Controller();
    ~Controller() = default;
    void ejecutar();

    void reactonP1Lclick();
    void reactonP1Rclick();
    void reactonClose();
  };
};

#endif //MVC_ARCHITECTURE_SFML_CONTROLLER_H

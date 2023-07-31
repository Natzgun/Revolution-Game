#ifndef MVC_ARCHITECTURE_SFML_MODEL_H
#define MVC_ARCHITECTURE_SFML_MODEL_H

// Archivo Model.h
#pragma once
#include "Juego.h"
#include <memory>

namespace Ctlr {
  class Controller;
}
namespace Mdl {
  class Model {
  private:
    std::shared_ptr<Ctlr::Controller> mediator;
  public:
    Juego myJuego;
    /*Menu myMenu;*/
    // Atributos y datos del modelo

    Model();
    void setMediator(Ctlr::Controller* mediator_);
    void actualizar();
    // Métodos y funciones relacionados con la lógica y los datos del modelo
  };
};

#endif //MVC_ARCHITECTURE_SFML_MODEL_H

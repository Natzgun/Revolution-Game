#include "Model.h"
#include "../Controller/Controller.h"

namespace Mdl{
  Model::Model() {
    myJuego = Juego();
  }
  void Model::actualizar() {
    myJuego.actualizar();
  }

  void Model::setMediator(Ctlr::Controller *mediator_) {
    mediator = std::shared_ptr<Ctlr::Controller>(mediator_);
  }
};


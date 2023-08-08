#include "Model.h"
#include "../Controller/Controller.h"

namespace Mdl{
  Model::Model() {
//    myJuego = Juego();
  }
  void Model::actualizar() {
    myJuego.actualizar();
  }

  void Model::setMediator(Ctlr::Controller *mediator_) {
    mediatorRef = mediator_;
  }

  Model::~Model() {
//    delete myJuego;
  }

  void Model::reactonLclick() {
    myJuego.p1->disparar();
  }

  void Model::reactonRclick() {
    myJuego.p1->lanzar();
  }
};

#include "Model.h"
#include "../Controller/Controller.h"

void Mdl::Model::setMediator(Ctlr::Controller *mediator_) {
  mediatorRef = mediator_;
}

void Mdl::Model::setMousePos(Vector2d<float> mouse) {
  mousePos = mouse;
}

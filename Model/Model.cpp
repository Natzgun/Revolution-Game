#include "Model.h"
#include "../Controller/Controller.h"

void Mdl::Model::setMediator(Ctlr::Controller *mediator_) {
  mediatorRef = mediator_;
}

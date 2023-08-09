#ifndef REVOLUTION_GAME_MODELO_H
#define REVOLUTION_GAME_MODELO_H

#include "../Util/Vector2d.h"
#include <string>

namespace Ctlr {
  class Controller;
}

namespace Mdl {
  class Model {
  private:
    Ctlr::Controller* mediatorRef;
    Vector2d<float> mousePos;
  public:
    Model() = default;
    ~Model() = default;

    virtual void actualizar() = 0;
    virtual void handleEvent(std::string) = 0;
    void setMousePos(Vector2d<float> mouse);
    void setMediator(Ctlr::Controller* mediator_);
  };
};

#endif //REVOLUTION_GAME_MODELO_H

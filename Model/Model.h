#ifndef REVOLUTION_GAME_MODELO_H
#define REVOLUTION_GAME_MODELO_H

#include <string>

namespace Ctlr {
  class Controller;
}

namespace Mdl {
  class Model {
  private:
    Ctlr::Controller* mediatorRef;
  public:
    Model() = default;
    ~Model() = default;

    virtual void actualizar() = 0;
    virtual void handleEvent(std::string) = 0;
    void setMediator(Ctlr::Controller* mediator_);
  };
};

#endif //REVOLUTION_GAME_MODELO_H

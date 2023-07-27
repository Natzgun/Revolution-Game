#ifndef MVC_ARCHITECTURE_SFML_MODEL_H
#define MVC_ARCHITECTURE_SFML_MODEL_H

// Archivo Model.h
#pragma once
#include "Juego.h"
#include "MainMenu.h"

namespace Mdl {
    class Model {
    private:
      Juego *myJuego ;
      MainMenu *myMenu;
      string estado;
    public:

        // Atributos y datos del modelo

        Model();
        void actualizar();
        ~Model(){
          delete myJuego;
          delete myMenu;
        }
        // Métodos y funciones relacionados con la lógica y los datos del modelo
    };
};

#endif //MVC_ARCHITECTURE_SFML_MODEL_H

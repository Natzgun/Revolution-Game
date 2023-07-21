#ifndef MVC_ARCHITECTURE_SFML_MODEL_H
#define MVC_ARCHITECTURE_SFML_MODEL_H

// Archivo Model.h
#pragma once
#include "Juego.h"

namespace Mdl {
    class Model {
    public:
        Juego myJuego;
        /*Menu myMenu;*/
        // Atributos y datos del modelo

        Model();
        void actualizar();
        // Métodos y funciones relacionados con la lógica y los datos del modelo
    };
};

#endif //MVC_ARCHITECTURE_SFML_MODEL_H

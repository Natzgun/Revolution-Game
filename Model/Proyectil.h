//
// Created by msumi on 6/07/2023.
//

#ifndef REVOLUTION_GAME_PROYECTIL_H
#define REVOLUTION_GAME_PROYECTIL_H
#include "Entidad.h"
#include <string>

class Proyectil:public Entidad {
private:
    constexpr static float rapi = 15;
    static string clave;
    Vector2d<float> velocidad;
public:
    Proyectil();
    Proyectil(Vector2d<float> unitario, Vector2d<float> posicion);
    virtual void actualizar();
    virtual ~Proyectil(){};
};


#endif //REVOLUTION_GAME_PROYECTIL_H

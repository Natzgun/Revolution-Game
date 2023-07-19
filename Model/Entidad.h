#ifndef REVOLUTION_GAME_ENTIDAD_H
#define REVOLUTION_GAME_ENTIDAD_H

#include <vector>
#include "Vector2d.h"
using namespace std;

class Entidad {
protected:
    Vector2d<int> dimension;
    Vector2d<int> posicion;
    Vector2d<int> posicion_central;
public:
    Entidad();
    Entidad(int x, int y);

    const Vector2d<int> &getPosicion() const;
    void setPosicion(int x,int y);

    const Vector2d<int> &getPosicionCentral() const;
    void setPosicionCentral(int x, int y);

    const Vector2d<int> &getDimension() const;
    void setDimension(int x, int y);

    virtual void actualizar() = 0;
    virtual ~Entidad() = default;
};

#endif //REVOLUTION_GAME_ENTIDAD_H

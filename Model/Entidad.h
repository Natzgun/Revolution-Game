#ifndef REVOLUTION_GAME_ENTIDAD_H
#define REVOLUTION_GAME_ENTIDAD_H

#include <vector>
#include "../Util/Vector2d.h"
using namespace std;

class Entidad {
protected:
    Vector2d<float> dimension;
    Vector2d<float> posicion;
    Vector2d<float> posicion_central;
public:
    Entidad();
    Entidad(float x, float y);
    bool checkColision(Entidad* otro);
    bool colisionX(Entidad* otro);
    bool colisionY(Entidad* otro);

    const Vector2d<float> &getPosicion() const;
    void setPosicion(float x,float y);

    const Vector2d<float> &getPosicionCentral() const;
    void setPosicionCentral(float x, float y);

    const Vector2d<float> &getDimension() const;
    void setDimension(float x, float y);

    virtual void actualizar() = 0;
    virtual ~Entidad() = default;

    void setTop(float);
    void setBottom(float);
    void setLeft(float);
    void setRight(float);
    void setCenter(Vector2d<float>);

    float getTop();
    float getBottom();
    float getLeft();
    float getRight();
    Vector2d<float> getCenter();

};

#endif //REVOLUTION_GAME_ENTIDAD_H

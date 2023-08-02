//
// Created by msumi on 5/07/2023.
//

#ifndef REVOLUTION_GAME_ITEM_H
#define REVOLUTION_GAME_ITEM_H
#include "Entidad.h"
#include "Proyectil.h"
class Stage;
class Item: public Entidad{
protected:
    int couldown;
    //velocidad=0;
    //acel=2;
    float rapi=0;
    Vector2d<float> facing;
    bool stunMode;
public:
    friend class Stage;
    Item();
    virtual void usar(Vector2d<float> dir, Vector2d<float> pos)=0;

    //v
    virtual void actualizar();
    virtual ~Item(){}
    Item(float x,float y):Entidad(x,y){};
    void imprimir();
    void lanzar(Vector2d<float> dir,Vector2d<float> pos);
};


#endif //REVOLUTION_GAME_ITEM_H

//
// Created by msumi on 5/07/2023.
//

#ifndef REVOLUTION_GAME_FIREGUN_H
#define REVOLUTION_GAME_FIREGUN_H
#include "Item.h"
#include "memory"
#include <map>

class Firegun: public Item {
public:

    int balas;
    virtual void usar(Vector2d<float> dir, Vector2d<float> pos);
    Firegun()=default;
    Firegun(float x, float y);
    virtual ~Firegun(){};
};


#endif //REVOLUTION_GAME_FIREGUN_H

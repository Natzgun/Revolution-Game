//
// Created by msumi on 5/07/2023.
//

#include "Firegun.h"
#include "GameWorld.h"
#include "Proyectil.h"
#include "memory"

void Firegun::usar(Vector2d<float> dir, Vector2d<float> pos) {
    if(couldown == 0) {
        balas--;
        couldown = 10;
        GameWorld::proyectiles.push_back(std::make_unique<Proyectil>(dir, pos));
    }
}

Firegun::Firegun(float x, float y) : Item(x, y) {
    balas = 4;
    couldown = 0;
}


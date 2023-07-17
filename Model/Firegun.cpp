//
// Created by msumi on 5/07/2023.
//

#include "Firegun.h"

Proyectil Firegun::usar(Vector2d<float> dir, Vector2d<int> pos) {
    balas--;
    couldown = 10;
    return Proyectil(dir, pos);
}


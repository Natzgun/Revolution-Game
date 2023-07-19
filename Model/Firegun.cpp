//
// Created by msumi on 5/07/2023.
//

#include "Firegun.h"
# include "Juego.h"
#include "Proyectil.h"
void Firegun::usar(Vector2d<float> dir, Vector2d<int> pos) {
    if(couldown == 0) {
        balas--;
        couldown = 10;
        Juego::proyectiles.push_back(make_unique<Proyectil>(dir, pos));
    }
}

Firegun::Firegun(int x, int y) : Item(x, y) {
    balas = 4;
    couldown = 0;
}


//
// Created by msumi on 27/06/2023.
//

#include "Juego.h"

Juego::Juego(string path) {
    p1 = new Jugador();
    nivel = Stage(path);
    matrizEscenario = path;
}
void Juego::actualizar() {
    p1->actualizar();
}

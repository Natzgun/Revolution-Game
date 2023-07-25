#include "Model.h"

Mdl::Model::Model() {
    myJuego = Juego();
    myMenu = MainMenu();
}
void Mdl::Model::actualizar() {
    myJuego.actualizar();
    myMenu.actualizar();
}

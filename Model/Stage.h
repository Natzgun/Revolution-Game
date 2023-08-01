//
// Created by pickle on 11/07/23.
//

#ifndef REVOLUTION_GAME_STAGE_H
#define REVOLUTION_GAME_STAGE_H
#include "Item.h"
#include <memory>

//#include <string>
#include <vector>
#include "Firegun.h"

class Stage {
private:
    static int rows,cols;
    std::vector<unique_ptr<Item>> arrItems;
  // vector de punteros crudos a enemigos
  //
public:
    Stage()=default;
  Stage(const string& matrizStage);
  void generarMatriz(string file);
  void actualizar();
  void genEmptyLvl();
  void imprimir();
};


#endif // REVOLUTION_GAME_STAGE_H

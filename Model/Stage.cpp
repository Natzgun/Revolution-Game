//
// Created by pickle on 11/07/23.
//

#include "Stage.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>

int Stage::rows = 18;//720
int Stage::cols = 32;//1280
Stage::Stage(const string& matrizStage) {
  generarMatriz(matrizStage);
  genEmptyLvl();
  itemsXObstaculos = vector<vector<bool>>(arrItems.size(),vector<bool>(arrObstaculos.size(),false));
}

void Stage::generarMatriz(string file) {

    std::ifstream archivo(file);
    string linea;
    int c = 0;
    int kIndex;
    bool primero = true;
    if(archivo.is_open()){
        int matriz [rows][cols];
        cout<<"==================================================================="<<endl;
        while(std::getline(archivo,linea)&&c!=18) {
            cout<<"| ";
            for(int i = 0; i<32;i++){
                if(primero) {// error primera linea con un espacio en blanco extra
                    kIndex = (2 * i) + 3;
                }
                else
                    kIndex = 2*i;

                if(linea[kIndex] == '0') {
                    matriz[c][i] = 0;
                }
                else if(linea[kIndex] == '1') {
                    matriz[c][i] = 1;
                }
                matriz[c][i]==0? cout<<"  " :cout<<matriz[c][i]<<" ";
            }
            primero = false;
            cout<<"|"<<endl;

            c ++;
        }
        cout<<"==================================================================="<<endl<<endl;
        for(int j=0;j<rows;j++){
            for(int h=0;h<cols;h++){
                if(matriz[j][h] == 1){
                    arrItems.push_back(make_unique<Firegun>(j*40,h*40));
                    cout<<"se agraga un nuevo item en "<<j<<","<<h<<endl;

                }
            }
        }
    }
    else{
        std::cout<<"no se puede abrir el archivo"<<endl;
    }


}

void Stage::genEmptyLvl() {
  //rows 18*3 = 48 (por 40) Y
  //cols 32*3 = 96 (por 40) X
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      arrObstaculos.push_back(new Obstaculo(32 * i, 18 * j, 96 - 2, 2));
      arrObstaculos.push_back(new Obstaculo(32 * i, 18 * j, 2, 48 - 2));
    }
  }
}
void Stage::genEmptyCell() {
}

void Stage::imprimir() {
    for(int i=0;i< this->arrItems.size();i++){
        arrItems[i]->imprimir();
        cout<<endl;
    }
}

void Stage::actualizar() {
    for(size_t i=0;i< this->arrItems.size();i++){
        arrItems[i]->actualizar();
        for (size_t j=0; j< this->arrObstaculos.size();j++){
          // condicion para rebote
          if(itemsXObstaculos[i][j]&&arrItems[i]->colisionY(arrObstaculos[j])){
            arrItems[i]->facing.setX(arrItems[i]->facing.getX()*-1);
          }
          else if(arrItems[i]->checkColision(arrObstaculos[j])){
            arrItems[i]->facing.setY(arrItems[i]->facing.getY()*-1);
          }

          //actualizar matriz bool de colision en X
          itemsXObstaculos[i][j] = arrItems[i]->colisionX(arrObstaculos[j]);
        }
    }
}

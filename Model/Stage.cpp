//
// Created by pickle on 11/07/23.
//

#include "Stage.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>


Stage::Stage(const string& matrizStage) {
    rows = 18;
    cols = 32;
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
        while(std::getline(archivo,linea)) {
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
                    arrItems.push_back(make_unique<Firegun>(j*500,h*500));
                    cout<<"se agraga un nuevo item en "<<j<<","<<h<<endl;

                }
            }
        }
    }
    else{
        std::cout<<"no se puede abrir el archivo"<<endl;
    }
}

void Stage::imprimir() {
    for(int i=0;i< this->arrItems.size();i++){
        arrItems[i]->imprimir();
        cout<<endl;
    }
}

void Stage::actualizar() {
    for(int i=0;i< this->arrItems.size();i++){
        arrItems[i]->actualizar();
    }
}

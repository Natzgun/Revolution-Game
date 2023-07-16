//
// Created by pickle on 11/07/23.
//

#include "Stage.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <memory>


Stage::Stage(string matrizStage) {
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
        while(std::getline(archivo,linea)) {
            //cout<<"{"<<linea<<"} -> "<<linea.size()<<endl;
            for(int i = 0; i<32;i++){
                if(primero) {// error primera linea con un espacio en blanco extra
                    kIndex = (2 * i) + 3;
                    //cout<<"si pasa "<<linea[5]<<" "<<kIndex<<endl;
                }
                else
                    kIndex = 2*i;

                //cout<<"{"<<linea[kIndex]<<"}";
                if(linea[kIndex] == '0') {
                    matriz[c][i] = 0;
                    //cout<<"["<<matriz[c][i]<<"]";
                }
                else if(linea[kIndex] == '1') {
                    matriz[c][i] = 1;
                }
                cout<<""<<matriz[c][i]<<" ";
            }
            primero = false;
            cout<<endl;

            c ++;
        }
        cout<<endl;
        for(int j=0;j<rows;j++){
            for(int h=0;h<cols;h++){
                //cout<<"["<<matriz[j][h]<<"] ";
                if(matriz[j][h] == 1){
                    unique_ptr<Item> temp = make_unique<Firegun>();
                    arrItems.push_back(make_unique<Firegun>());
                    cout<<"se agraga un nuevo item en "<<j<<","<<h<<endl;
                }
            }
            //cout<<endl;
        }
    }
    else{
        std::cout<<"no se puede abrir el archivo"<<endl;
    }
}

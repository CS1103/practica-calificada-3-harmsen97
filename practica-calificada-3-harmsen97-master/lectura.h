//
// Created by Jeronimo on 2019-11-07.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>


#ifndef PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_LECTURA_H
#define PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_LECTURA_H



std::map<std::string, std::pair<std::string, int>> lectura(std::string filename){
    std::map<std::string, std::pair<std::string, int>> subasta;

    std::ifstream file(filename, std::ios::in);
    std::string str;

    std::string producto;
    std::string usuario;
    while (file>>str) {
        if (isupper(str[0])){
            std::string aux;
            std::getline(file, aux);
            producto = str + aux;
        }
        else{
            usuario = str;
            int monto;
            file >> monto;
            auto it = subasta.find(usuario);
            if(it!=subasta.end()){
                if(it->second.first != producto or monto < 0) {
                    subasta.erase(it);
                }
            }
            else {
                subasta[usuario] = std::make_pair(producto, monto);
            }
        }
    }
    return subasta;
}

#endif //PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_LECTURA_H

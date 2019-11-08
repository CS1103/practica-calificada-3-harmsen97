//
// Created by Jeronimo on 2019-11-07.
//


#include <map>


#ifndef PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_LECTURA_H
#define PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_LECTURA_H

std::map<std::string, std::string> lectura(){
    std::map<std::string, std::string> subasta;

    std::ifstream file("bid_examples.txt", std::ios::in);
    std::string str;

    std::string producto;
    std::string usuario;
    while (std::getline(file, str)) {
        if (isupper(str[0])){
            producto = str;
        }
        else{
            usuario = str;
            subasta[usuario] = producto;
        }
    }
    return subasta;
}

#endif //PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_LECTURA_H

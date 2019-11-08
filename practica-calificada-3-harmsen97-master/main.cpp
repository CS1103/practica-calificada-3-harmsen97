#include <iostream>

#include "lectura.h"
#include "operaciones.h"


    int main (){

        std::map<std::string, std::pair<std::string, int>> sub = lectura("../bid_example.txt");

        escritura(sub, "../test1.txt");
    }






#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void lectura(){

    std::vector<std::string> productos;
    std::vector<std::string> usuarios;

    std::ifstream file("bid_examples.txt");
    std::string str;


    while (std::getline(file, str)) {

        if (isupper(str[0])){

            productos.push_back(str);


        }
        else{

            usuarios.push_back(str);


        }
        usuarios.push_back(" --- ");


    }

}

std::vector<int> OfertaUsuarios(std::vector<std::string> usuarios){

    //esta funcion separa el nombre del usuario de la oferta asociada


}

int promedio(std::vector<std::string> x){

    for (int i =0; i<x.size(); ++i){

        //recibe el vector de ususarios y calcula el promedio,
        //separar nombre de usuario del usuario





    }

}


        int main (){


    





}


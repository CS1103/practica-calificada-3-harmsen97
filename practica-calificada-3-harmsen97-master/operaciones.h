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

#ifndef PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_OPERACIONES_H
#define PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_OPERACIONES_H


void print_summart(std::map<std::string, std::pair<std::string, int>> sub){
    for(auto&i:sub)
        std::cout<<i.first<<' '<<i.second.first<<' '<<i.second.second<<'\n';
}

bool comp(std::pair<std::string, int>&a, std::pair<std::string, int>&b){
    return a.second>b.second;
}

std::vector<std::pair<std::string, int>> OfertasUsuarios(std::string producto, std::map<std::string, std::pair<std::string, int>> subasta){
    std::vector<std::pair<std::string, int>> ofertas;
    for(auto&j:subasta){
        if(producto == j.second.first)
            ofertas.push_back(std::make_pair(j.first, j.second.second));
    }
    std::sort(ofertas.begin(),ofertas.end(), comp);
    return ofertas;
}

void InfoProducto(std::ofstream& out, std::string producto, std::map<std::string, std::pair<std::string, int>> subasta){
    out<<producto<<',';
    int max = 0, min = INT_MAX, sum = 0, count = 0;
    for(auto&j:subasta){
        if(producto == j.second.first){
            sum += j.second.second;
            if(max < j.second.second) {
                max = j.second.second;
            }
            if(min > j.second.second) {
                min = j.second.second;
            }
            count++;
        }
    }
    out<<max<<','<<(double)sum/count<<','<<min<<'\n';
}

void escritura(std::map<std::string, std::pair<std::string, int>>& subasta, std::string filename) {

    std::ofstream output(filename, std::ios::out);

    std::map<std::string, int> productos;

    for(auto&i:subasta)
        productos[i.second.first]++;

    for(auto&i:productos){
        InfoProducto(output, i.first, subasta);

        auto ofertas = OfertasUsuarios(i.first, subasta);

        for(auto&j:ofertas)
            output<<j.first<<' '<<j.second<<'\n';
    }
}


#endif //PRACTICA_CALIFICADA_3_HARMSEN97_MASTER_OPERACIONES_H

#include "rainhas.hpp"
#include <iostream>
#include <string>

bool verifica_tabuleiro(std::string tabul) {
    bool juri = true;
    int contador = 0;
    int tam = tabul.length();
    if (tam != 71) {
        juri = false;
    }
    for (int u = 0; u < tam; u += 1) {
        if (tabul[u] == ',' && contador != 1) {
            juri = false;
            break;
        } else if (tabul[u] == ',' && contador == 1){
            contador = 0;
        } else if (tabul[u] == '1'){
            contador += 1;
        }
    }
    return juri;
};


int problema_8_rainhas(std::string tabuleiro) {
    if (verifica_tabuleiro(tabuleiro) == true) {
        return 1;
    } else {
        return -1;
    }
};

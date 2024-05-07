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
    for (int i = 0; i < tam; i += 1) {
       if (tabul[i] == '1') {
        contador += 1;
       }
    }
    if (contador != 8) {
        juri = false;
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

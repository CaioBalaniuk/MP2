#include "rainhas.hpp"
#include <iostream>
#include <string>

std::string le_arquivo(std::string& nomeArquivo) {
    std::string resp = "";
    std::string respf = "";
    std::ifstream arquivo(nomeArquivo);
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            resp += linha;
            resp += ',';
        }
        for (int i = 0; i < (resp.length()-1); i +=1) {
            respf += resp[i];
        }
        arquivo.close();
    } else {
        std::cout<<"Erro ao abrir arquivo."<<std::endl;
    }
    return respf;
}

bool verifica_tabuleiro(std::string tabul) {
    bool juri = true;
    int contador = 0;
    int contador1 = 0;
    int tam = tabul.length();
    if (tam != 71) {
        juri = false;
    }
    for (int u = 0; u < tam; u += 1) {
        if ((tabul[u] == ',' && contador != 1) || (tabul[u] == ',' && contador1 != 8)) {
            juri = false;
            break;
        } else if (tabul[u] == ',' && contador == 1){
            contador = 0;
            contador1 = 0;
        } else if (tabul[u] == '1'){
            contador += 1;
            contador1 +=1;
        } else if (tabul[u] == '0'){
            contador1 += 1;
        }
    }
    return juri;
};


int problema_8_rainhas(std::string nomeArquivo) {
    std::string tabuleiro = le_arquivo(nomeArquivo);
    if (verifica_tabuleiro(tabuleiro) == true) {
        return 1;
    } else {
        return -1;
    }
};

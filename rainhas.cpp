#include "rainhas.hpp"
#include <iostream>
#include <string>
#include <vector>

void imprimir(std::vector<std::vector<int>> a) {
    for (std::vector<int> u : a) {
        for (int u1 : u) {
            std::cout<<u1;
        }
        std::cout<<std::endl;
    }
}

void imprimir1(std::vector<int> b) {
    for (int u2 : b) {
        std::cout<<u2;
    }
    std::cout<<std::endl;
}

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

std::vector<std::vector<int>> matriz (std::string tab) {
    std::vector<int> apoio = {};
    std::vector <std::vector<int>> resp;
    for (int i = 0; i < tab.length(); i += 1) {
        if (tab[i] == ',') {
            resp.push_back(apoio);
            apoio = {};
        } else {
            int a = tab[i] - '0';
            apoio.push_back(a);
        }
    }
    return resp;
}

 std::string verifica_coluna(std::vector <std::vector<int>> matri, int linha, int coluna) {
    std::string resp = "";
    for (int i = 0; i < matri.size(); ++i) {
        if (i != linha) {
            matri[i][coluna] += 1;
        }
    }
    for (int u = 0; u < matri.size(); ++u) {
        if (matri[u][coluna] > 1) {
            resp += std::to_string(u);
            resp += ',';
            resp += std::to_string(coluna);
        }
    }
    return resp;
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
    if (verifica_tabuleiro(tabuleiro) == true){
        std::string ataques = "";
        std::vector<std::vector<int>> b;
        b = matriz(tabuleiro);
        for (int i = 0; i < b.size(); ++i) {
            //std::vector<int> ajuda = b[i];
            for (int i1 = 0; i1 < b[i].size(); ++i1) {
                if (b[i][i1] == 1) {
                    if (verifica_coluna(b, i, i1) != "" ) {
                        //ataques += std::to_string(i);
                        //ataques += ',';
                        //ataques += std::to_string(i1);
                        //ataques += " ";
                        ataques += verifica_coluna(b, i, i1);
                        ataques += " ";
                    }
                }
            }
        }
        if (ataques == "") {
            return 1;
        } else {
            return 0;
        }
    } else {
        return -1;
    }
};

/*int main() {
    std::cout<<problema_8_rainhas("teste_10.txt");
    return 0;
}*/

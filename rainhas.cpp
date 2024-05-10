#include "rainhas.hpp"
#include <iostream>
#include <string>
#include <vector>

void ataques_txt(std::vector<std::string> ataq, std::string nome) {
    std::string aux = "ataques_";
    std::string aux1 = "";
    for (char q : nome) {
        if (q >= '0' && q <= '9') {
            aux1 += q;
        }
    }
    aux += aux1;
    aux += ".txt";
    std::ofstream arquivo(aux);
    if (!arquivo.is_open()) {
        std::cout<<"Erro ao abrir arquivo"<<std::endl;
    }
    for (std::string k : ataq) {
        arquivo<<k<<std::endl;
    }

    arquivo.close();
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
    std::vector<int> apoio;
    std::vector <std::vector<int>> resp;
    int b = tab.length();
    for (int i = 0; i < b; i += 1) {
        if (tab[i] == ',') {
            resp.push_back(apoio);
            apoio = {};
        } else if (i == b - 1) {
            int a = tab[i] - '0';
            apoio.push_back(a);
            resp.push_back(apoio);
        } else {
            int a = tab[i] - '0';
            apoio.push_back(a);
        }
    }

    return resp;
}

std::string verifica_diagonal(std::vector <std::vector<int>> mat, int li, int co) {
    std::string re = "";
    int ta = mat.size();
    int soma = li + co;
    int sub = li - co;
    for (int m = 0; m < ta; ++m) {
        if (m != li) {
            int ta1 = mat[m].size();
            for ( int m1 = 0; m1 < ta1; ++m1) {
                if (m1 != co) {
                    int soma1 = m1 + m;
                    int sub1 = m - m1;
                    if (m1 < co) {
                        if (m < li) {
                            if (sub == sub1) {
                                mat[m][m1] += 1;
                            }
                        } else if (m > li) {
                            if (soma == soma1) {
                                mat[m][m1] += 1;
                            }
                        }
                    } else {
                        if (m < li) {
                            if (soma == soma1) {
                                mat[m][m1] += 1;
                            }
                        } else if (m > li) {
                            if (sub == sub1) {
                                mat[m][m1] += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int l = 0; l < ta; ++l) {
        for (int l1 = 0; l1 < 8; ++l1) {
            if (mat[l][l1] > 1) {
                re += std::to_string(l);
                re += ',';
                re += std::to_string(l1);
                re += " ";
                re += std::to_string(li);
                re += ',';
                re += std::to_string(co);
                re += " ";
            }
        }
    }
    return re;
}

std::string verifica_linha(std::vector <std::vector<int>> matri, int linha, int coluna) {
    std::string resp = "";
    int tam = matri.size();
    for (int i = 0; i < tam; ++i) {
        if (i != coluna) {
            matri[linha][i] += 1;
        }
    }
    for (int u = 0; u < tam; ++u) {
        if (matri[linha][u] > 1) {
            resp += std::to_string(linha);
            resp += ',';
            resp += std::to_string(u);
            resp += " ";
            resp += std::to_string(linha);
            resp += ',';
            resp += std::to_string(coluna);
            resp += " ";
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
            resp += " ";
            resp += std::to_string(linha);
            resp += ',';
            resp += std::to_string(coluna);
            resp += " ";
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
        if (tabul[u] == '1'){
            contador += 1;
            contador1 +=1;
        }else if (tabul[u] == '0') {
            contador1 += 1;
        }
        if (tabul[u] == ',' && contador1 != 8) {
            juri = false;
            break;
        }
         if (tabul[u] == ',' && contador1 == 8) {
            contador1 = 0;
        }
    }
    if (contador != 8) {
        juri =false;
    }
    return juri;
};


int problema_8_rainhas(std::string nomeArquivo) {
    std::string tabuleiro = le_arquivo(nomeArquivo);
    if (verifica_tabuleiro(tabuleiro) == true){
        std::vector<std::string> ataques;
        std::vector<std::vector<int>> b;
        b = matriz(tabuleiro);
        int tam = b.size();
        for (int i = 0; i < tam; ++i) {
            int tam1 = b[i].size();
            for (int i1 = 0; i1 < tam1; ++i1) {
                if (b[i][i1] == 1) {
                    if (verifica_coluna(b, i, i1) != "" ) {
                        ataques.push_back(verifica_coluna(b, i, i1));
                    }
                }
            }
        }
        for (int n = 0; n < tam; ++n) {
            int tam2 = b[n].size();
            for (int i2 = 0; i2 < tam2; ++i2) {
                if (b[n][i2] == 1) {
                    if (verifica_linha(b, n, i2) != "") {
                        ataques.push_back(verifica_linha(b, n, i2));
                    }
                }
            }
        }
        for (int y = 0; y < tam; ++y) {
            for (int y1 = 0; y1 < 8; ++y1) {
                if (b[y][y1] == 1) {
                    if (verifica_diagonal(b, y, y1) != "") {
                        ataques.push_back(verifica_diagonal(b, y, y1));
                    }
                }
            }
        }
        if (ataques.empty()) {
            return 1;
        } else {
            ataques_txt(ataques, nomeArquivo);
            return 0;
        }
    } else {
        return -1;
    }
};

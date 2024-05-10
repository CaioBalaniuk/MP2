#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int problema_8_rainhas(std::string tabuleiro);
bool verifica_tabuleiro(std::string tabul);
std::string le_arquivo(std::string& nomeArquivo);
std::vector <std::vector<int>> matriz(std::string tab);
std::string verifica_coluna(std::vector <std::vector<int>> matri, int linha, int coluna);
std::string verifica_linha(std::vector <std::vector<int>> matri, int linha, int coluna);
std::string verifica_diagonal(std::vector <std::vector<int>> mat, int li, int co);
void ataques_txt(std::string ataq, std::string nome);


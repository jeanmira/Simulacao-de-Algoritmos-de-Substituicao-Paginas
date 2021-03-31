#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <stdlib.h>

using namespace std;

class Entrada
{
private:
    ifstream meuArquivo;      // Objeto padrão de <fstream>
    string nome;              // Recebe o nome do arquivo
    int linhas;               // Número de processos
    vector<int> dadosCentral; // Vetor que guarda os dados originais

public:
    Entrada(string caminho);                 // Construtor padrão
    ~Entrada();                              // Destrutor padrão
    void tamanhoArquivo();                   // Retorna o número de linhas e colunas
    void setPonteiro();                      // Elimina e retorna o marcador para posicao inicial do arquivo
    void retornaArquivo(vector<int> &dados); // Retorna o arquivo em forma de vetor
    void imprimiDados(vector<int> &dados);   // Imprime os dados de um vetor (Interno)
    void imprimiArquivo();                   // Imprimir os dados do arquivo (Usuário)
};

#endif

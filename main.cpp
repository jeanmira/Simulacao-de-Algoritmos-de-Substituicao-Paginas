#include <iostream>
#include <vector>
#include <string>

#include "entrada.h"

using namespace std;

int main(int argc, char const *argv[])
{
    char automatizado;
    vector<int> dados;

    cout << "Deseja colocar o nome do arquivo manualmente? Digite <s> para SIM e <n> para NAO: ";
    cin >> automatizado;

    // Se o usuario digitar 's' pega o nome do arquivo direto na main.cpp
    if (automatizado == 's')
    {
        Entrada arquivo();
        arquivo.retornaArquivo(dados);
    }
    // Se o usuario digitar 'n' pega o nome do arquivo no terminal
    else if (automatizado == 'n')
    {
        string nome;
        cout << "Qual o nome do arquivo: ";
        cin >> nome;
        Entrada arquivo(nome);
        arquivo.retornaArquivo(dados);
    }
    else
    {
        cout << "Erro na resposta. Execute novamente!" << endl;
    }

    // Imprimi o arquivo
    arquivo.imprimiArquivo();

    return 0;
}

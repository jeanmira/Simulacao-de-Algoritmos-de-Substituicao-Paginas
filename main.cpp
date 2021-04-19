#include <iostream>
#include <vector>
#include <string>

#include "pagina.h"
#include "substituicao.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> dados; // Vetor que contém os valores das referências

    int entrada = 0, quadros = 0, valorFifo = 0, valorLru = 0, valorOpt = 0;

    // Armazena os dados inseridos pelo usuário
    quadros = atoi(argv[1]); // Armazena a quantidade de quadros
    while ((!feof(stdin)))
    {
        scanf("%d\n", &entrada);
        dados.push_back(entrada); // Armazena a referências de acordo com o arquivo solicitado
    }

    Pagina p1(quadros, dados); // Cria as páginas e os quadros
    cout << quadros << " quadros" << endl;
    cout << dados.size() << " refs" << endl;

    Substituicao init(p1); // Inicia o algoritmo de substituição e insere os dados das páginas

    valorFifo = init.fifo(); // Análise do método de substituição de página First In, First Out (FIFO)
    valorLru = init.lru();   // Análise do método de substituição de página Least Recently Used (LRU)
    valorOpt = init.opt();   // Analise do método de substituição de página Algoritmo Ótimo (OPT)

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

#include "pagina.h"
#include "substituicao.h"

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

using namespace std;

int main(int argc, char *argv[])
{
    auto t_Antes = high_resolution_clock::now(); // Tempo antes
    vector<int> dados;                           // Vetor que contém os valores das referências
    int entrada = 0, quadros = 0;

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

    init.fifo(); // Análise do método de substituição de página First In, First Out (FIFO)
    init.lru();  // Análise do método de substituição de página Least Recently Used (LRU)
    init.opt();  // Analise do método de substituição de página Algoritmo Ótimo (OPT)

    auto t_Depois = high_resolution_clock::now();              // Tempo depois
    duration<double, std::milli> t_Total = t_Depois - t_Antes; // Tempo real
    // cout << "Tempo total de execução: " << t_Total.count() << " ms" << endl;

    return 0;
}

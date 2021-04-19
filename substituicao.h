#ifndef SUBSTITUICAO_H
#define SUBSTITUICAO_H

#include <vector>
#include <iostream>
#include <string>
#include <unistd.h>
#include <queue>
#include <list>
#include "pagina.h"
#include "interface.h"

using namespace std;

class Substituicao
{
private:
    Pagina P;       // Variável do tipo página que contém a quantidade de páginas e os valores de referência
    vector<int> pf; // Vetor de inteiros que guarda a quantidade de page fault

public:
    Substituicao(Pagina P); // Construtor padrão
    ~Substituicao();        // Destrutor padrão
    int fifo();             // Método de substituição de página First In, First Out (FIFO)
    int lru();              // Método de substituição de página Least Recently Used (LRU)
    int opt();              // Método de substituição de página Algoritmo Ótimo (OPT)
};

#endif

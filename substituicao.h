#ifndef SUBSTITUICAO_H
#define SUBSTITUICAO_H

#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include "pagina.h"

using namespace std;

class Substituicao
{
private:
    Pagina P;
    vector<int> pf;

public:
    Substituicao(Pagina P); // Construtor padrão
    ~Substituicao();        // Construtor padrão
    void fifo();
    void lru();
    void opt();
};

#endif
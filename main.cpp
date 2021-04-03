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
    vector<int> dados;
    int entrada = 0, quadros = 0;

    quadros = atoi(argv[1]);

    while ((!feof(stdin)))
    {
        scanf("%d\n", &entrada);
        dados.push_back(entrada);
    }

    Pagina p1(quadros, dados);
    cout << quadros << " quadros" << endl;
    cout << dados.size() << " refs" << endl;
    Substituicao init(p1);

    init.fifo();
    init.lru();
    init.opt();
    auto t_Depois = high_resolution_clock::now();              // Tempo depois
    duration<double, std::milli> t_Total = t_Depois - t_Antes; // Tempo real
    //cout << "Tempo total de execução: " << t_Total.count() << " ms" << endl;
    return 0;
}

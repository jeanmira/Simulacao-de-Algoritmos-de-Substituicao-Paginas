#include <iostream>
#include <vector>
#include <string>

#include "pagina.h"
#include "substituicao.h"

using namespace std;

int main(int argc, char *argv[])
{
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

    return 0;
}

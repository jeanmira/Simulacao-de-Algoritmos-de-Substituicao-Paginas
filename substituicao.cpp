#include "substituicao.h"

Substituicao::Substituicao(Pagina P)
{
    this->P = P;
}
Substituicao::~Substituicao()
{
}

void Substituicao::fifo()
{
    for (int i = 0; i < P.getQuadrosSize(); i++)
    {
        cout << P.getQuadros(i) << endl;
    }

    cout << P.getQuadrosSize() << endl
         << endl;

    for (int j = 0; j < P.getReferenciasSize(); j++)
    {
        cout << P.getReferencias(j) << endl;
    }
}

void Substituicao::lru() {}
void Substituicao::opt() {}
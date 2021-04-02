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
    P.reiniciaParametros();
    int cont = 1;
    for (int i = 0; i < P.getReferenciasSize(); i++)
    {
        for (int j = 0; j < P.getQuadrosSize(); j++)
        {
            //cout << "menor: " << P.getPosicaoMenorTempo() << endl;
            if (j == P.getPosicaoMenorTempo() && !P.verificaValorDeReferenciaEmQuadros(i))
            {

                P.setTempos(cont, j);
                P.setQuadros(P.getReferencias(i), j);
                cont++;
                // cout << cont << " | " << P.getQuadros(0) << " " << P.getQuadros(1) << " " << P.getQuadros(2) << " " << P.getQuadros(3) << " | " << P.getTempos(0) << " " << P.getTempos(1) << " " << P.getTempos(2) << " " << P.getTempos(3) << endl;
                break;
            }
        }
    }
    cont--;
    cout << "FIFO: " << cont << " PFs" << endl;
}

void Substituicao::lru()
{
    P.reiniciaParametros();
    int cont = 1, cont2 = 0;
    for (int i = 0; i < P.getReferenciasSize(); i++)
    {
        for (int j = 0; j < P.getQuadrosSize(); j++)
        {
            //cout << "menor: " << P.getPosicaoMenorTempo() << endl;
            if (j == P.getPosicaoMenorTempo() && !P.verificaValorDeReferenciaEmQuadros(i))
            {

                P.setTempos(cont, j);
                P.setQuadros(P.getReferencias(i), j);
                cont++;
                cont2++;
                //cout << cont << " | " << P.getQuadros(0) << " " << P.getQuadros(1) << " " << P.getQuadros(2) << " " << P.getQuadros(3) << " | " << P.getTempos(0) << " " << P.getTempos(1) << " " << P.getTempos(2) << " " << P.getTempos(3) << endl;
                break;
            }
            else if (j == P.getPosicaoMenorTempo() && P.verificaValorDeReferenciaEmQuadros(i))
            {
                P.setTempos(cont, P.getPosicaoDeReferenciaEmQuadros(i));
                cont++;
                break;
            }
        }
    }
    cout << "LRU: " << cont2 << " PFs" << endl;
}
void Substituicao::opt()
{
    P.reiniciaParametros();
    
    cout << "OPT: " << 1 << " PFs" << endl;
}
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
    queue<int> t;
    long int pf = 0;
    long int pf_ini = 0;
    int j = 0;

    while (pf_ini < P.getQuadrosSize() && j < P.getReferenciasSize())
    {
        if (!P.verificaValorDeReferenciaEmQuadros(j))
        {
            P.setQuadros(P.getReferencias(j), pf_ini);
            t.push(P.getReferencias(j));
            pf_ini++;
        }
        j++;
    }

    pf = pf_ini;
    for (int i = j; i < P.getReferenciasSize(); i++)
    {
        if (!P.verificaValorDeReferenciaEmQuadros(i))
        {
            t.push(P.getReferencias(i));
            for (int k = 0; k < P.getQuadrosSize(); k++)
            {
                if (P.getQuadros(k) == t.front())
                {
                    P.setQuadros(P.getReferencias(i), k);
                }
            }
            if (t.size() > P.getQuadrosSize())
            {
                t.pop();
            }
            pf++;
        }
    }
    cout << "FIFO: " << pf << " PFs" << endl;
}

void Substituicao::lru()
{
    P.reiniciaParametros();

    list<int> t;
    long int pf = 0;
    long int pf_ini = 0;
    int j = 0;

    while (pf_ini < P.getQuadrosSize() && j < P.getReferenciasSize())
    {
        if (!P.verificaValorDeReferenciaEmQuadros(j))
        {
            P.setQuadros(P.getReferencias(j), pf_ini);
            t.push_back(P.getReferencias(j));
            pf_ini++;
        }
        else
        {
            t.remove(P.getReferencias(j));
            t.push_back(P.getReferencias(j));
        }
        j++;
    }

    pf = pf_ini;
    for (int i = j; i < P.getReferenciasSize(); i++)
    {
        if (!P.verificaValorDeReferenciaEmQuadros(i))
        {
            t.push_back(P.getReferencias(i));
            for (int k = 0; k < P.getQuadrosSize(); k++)
            {
                if (P.getQuadros(k) == t.front())
                {
                    P.setQuadros(P.getReferencias(i), k);
                }
            }
            if (t.size() > P.getQuadrosSize())
            {
                t.pop_front();
            }
            pf++;
        }
        else
        {
            t.remove(P.getReferencias(i));
            t.push_back(P.getReferencias(i));
        }
    }
    cout << "LRU: " << pf << " PFs" << endl;
}

void Substituicao::opt()
{

    P.reiniciaParametros();
    queue<int> t;
    long int pf = 0;

    for (int i = 0; i < P.getReferenciasSize(); i++)
    {
        if (!P.verificaValorDeReferenciaEmQuadros(i))
        {
            P.setQuadros(P.getReferencias(i), P.getMaiorDiferenca(i + 1));
            pf++;
        }
    }
    cout << "OPT: " << pf << " PFs" << endl;
}
#include "substituicao.h"

//---- Construtor padrão
Substituicao::Substituicao(Pagina P)
{
    this->P = P;
}

//---- Destrutor padrão
Substituicao::~Substituicao()
{
}

//---- Método de substituição de página First In, First Out (FIFO)
void Substituicao::fifo()
{
    P.reiniciaParametros(); // Zera os quadros e tempos para próxima análise

    queue<int> t;
    long int pf = 0;
    long int pf_ini = 0;
    int j = 0;

    // Preenche o vetor de quadros e adiciona os valores na fila
    while (pf_ini < P.getQuadrosSize() && j < P.getReferenciasSize())
    {
        // Se o valor de referência não está contido no vetor de quadros
        if (!P.verificaValorDeReferenciaEmQuadros(j))
        {
            P.setQuadros(P.getReferencias(j), pf_ini); // Adiciona o valor da referência no vetor de quadros
            t.push(P.getReferencias(j));               // Adiciona os valores de referência na fila
            pf_ini++;                                  // Incrementa o page fault
        }
        j++;
    }

    pf = pf_ini; // Inicia o page fault

    for (int i = j; i < P.getReferenciasSize(); i++)
    {
        // Se o valor de referência não está contido no vetor de quadros

        if (!P.verificaValorDeReferenciaEmQuadros(i))
        {
            t.push(P.getReferencias(i)); // Adiciona os valores de referência na fila

            for (int k = 0; k < P.getQuadrosSize(); k++)
            {
                // Acha o valor de quadros que corresponde ao primeiro da fila
                if (P.getQuadros(k) == t.front())
                {
                    P.setQuadros(P.getReferencias(i), k); // Adiciona o valor de referência no vetor de quadros
                }
            }

            // Se a fila fica maior que a quantidade de quadros retira o primeiro
            if (t.size() > P.getQuadrosSize())
            {
                t.pop(); // Retira o primeiro valor de referência da fila
            }

            pf++; // Incrementa o page fault
        }
    }
    cout << "FIFO: " << pf << " PFs" << endl;
}

//---- Método de substituição de página Least Recently Used (LRU)
void Substituicao::lru()
{
    P.reiniciaParametros(); // Zera os quadros e tempos para próxima análise

    list<int> t;
    long int pf = 0;
    long int pf_ini = 0;
    int j = 0;

    // Preenche o vetor de quadros e adiciona os valores na lista
    while (pf_ini < P.getQuadrosSize() && j < P.getReferenciasSize())
    {
        // Se o valor de referência não está contido no vetor de quadros
        if (!P.verificaValorDeReferenciaEmQuadros(j))
        {
            P.setQuadros(P.getReferencias(j), pf_ini); // Adiciona o valor da referência no vetor de quadros
            t.push_back(P.getReferencias(j));          // Adiciona os valores de referência na lista
            pf_ini++;                                  // Incrementa o page fault
        }
        else
        {
            t.remove(P.getReferencias(j));    //  Se o valor de referência está contido no vetor de quadros retira o valor da lista
            t.push_back(P.getReferencias(j)); // E adiciona ele no final da lista
        }
        j++;
    }

    pf = pf_ini; // Inicia o page fault

    for (int i = j; i < P.getReferenciasSize(); i++)
    {
        // Se o valor de referência não está contido no vetor de quadros
        if (!P.verificaValorDeReferenciaEmQuadros(i))
        {
            t.push_back(P.getReferencias(i)); // Adiciona os valores de referência na lista

            for (int k = 0; k < P.getQuadrosSize(); k++)
            {
                // Acha o valor de quadros que corresponde ao primeiro da lista
                if (P.getQuadros(k) == t.front())
                {
                    P.setQuadros(P.getReferencias(i), k); // Adiciona o valor de referência no vetor de quadros
                }
            }

            // Se a lista fica maior que a quantidade de quadros retira o primeiro
            if (t.size() > P.getQuadrosSize())
            {
                t.pop_front(); // Retira o primeiro valor de referência da lista
            }

            pf++; // Incrementa o page fault
        }
        else
        {
            t.remove(P.getReferencias(i));    //  Se o valor de referência está contido no vetor de quadros retira o valor da lista
            t.push_back(P.getReferencias(i)); // E adiciona ele no final da lista
        }
    }
    cout << "LRU: " << pf << " PFs" << endl;
}

//---- Método de substituição de página Algoritmo Ótimo (OPT)
void Substituicao::opt()
{

    P.reiniciaParametros(); // Zera os quadros e tempos para próxima análise

    long int pf = 0;

    for (int i = 0; i < P.getReferenciasSize(); i++)
    {
        // Se o valor de referência não está contido no vetor de quadros
        if (!P.verificaValorDeReferenciaEmQuadros(i))
        {
            P.setQuadros(P.getReferencias(i), P.getMaiorDiferenca(i + 1)); // Adiciona o valor de referência no vetor de quadros
            pf++;                                                          // Incrementa o page fault
        }
    }
    cout << "OPT: " << pf << " PFs" << endl;
}
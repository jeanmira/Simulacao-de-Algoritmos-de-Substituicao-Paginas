
#include "pagina.h"

Pagina::Pagina()
{
}

Pagina::Pagina(const Pagina &outro)
{

    this->quadros = outro.quadros;
    this->referencias = outro.referencias;
    this->tempos = outro.tempos;
}

Pagina::Pagina(int q, vector<int> &r)
{
    for (int i = 0; i < q; i++)
    {
        this->quadros.push_back(-1);
        this->tempos.push_back(0);
    }
    for (int j = 0; j < r.size(); j++)
    {
        this->referencias.push_back(r[j]);
    }
}

Pagina::~Pagina()
{
}
void Pagina::setQuadros(int r, int i)
{
    this->quadros[i] = r;
}
void Pagina::setTempos(int r, int i)
{
    this->tempos[i] = r;
}
int Pagina::getTempos(int i)
{
    return this->tempos[i];
}
int Pagina::getQuadros(int i)
{
    return this->quadros[i];
}
int Pagina::getReferencias(int i)
{
    return this->referencias[i];
}
int Pagina::getReferenciasSize()
{
    return this->referencias.size();
}
int Pagina::getQuadrosSize()
{
    return this->quadros.size();
}
int Pagina::getPosicaoMenorTempo()
{
    int aux = referencias.size() + 1, posicao = 0;
    for (int j = 0; j < tempos.size(); j++)
    {
        if (tempos[j] < aux)
        {
            aux = tempos[j];
            posicao = j;
        }
    }

    return posicao;
}

bool Pagina::verificaValorDeReferenciaEmQuadros(int i)
{
    for (int j = 0; j < quadros.size(); j++)
    {
        if (referencias[i] == quadros[j])
        {
            return true;
        }
    }
    return false;
}
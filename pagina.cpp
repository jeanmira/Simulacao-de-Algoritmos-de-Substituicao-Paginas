
#include "pagina.h"

Pagina::Pagina()
{
}

Pagina::Pagina(const Pagina &outro)
{

    this->quadros = outro.quadros;
    this->referencias = outro.referencias;
}

Pagina::Pagina(int q, vector<int> &r)
{
    for (int i = 0; i < q; i++)
    {
        this->quadros.push_back(0);
    }
    for (int j = 0; j < r.size(); j++)
    {
        this->referencias.push_back(r[j]);
    }
}

Pagina::~Pagina()
{
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

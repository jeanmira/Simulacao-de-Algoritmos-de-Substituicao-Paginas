
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

int Pagina::getPosicaoDeReferenciaEmQuadros(int i)
{
    for (int j = 0; j < quadros.size(); j++)
    {
        if (referencias[i] == quadros[j])
        {
            return j;
        }
    }
    return -1;
}

void Pagina::reiniciaParametros()
{
    for (int i = 0; i < quadros.size(); i++)
    {
        this->quadros[i] = -1;
        this->tempos[i] = 0;
    }
}

int Pagina::getMaiorDiferenca(int inicial)
{
    int temp = 0, posicao = 0;
    vector<int> aux(quadros.size());

    for (int i = 0; i < quadros.size(); i++)
    {
        aux[i] = -1;
    }

    for (int j = 0; j < quadros.size(); j++)
    {
        //cout << "q" << j << endl;
        for (int i = inicial; i < referencias.size(); i++)
        {
            //cout << "--" << quadros[j] << " " << referencias[i] << endl;
            if (quadros[j] == referencias[i])
            {
                aux[j] = i;
                break;
            }
            else
            {
                aux[j] = (referencias.size() + 1);
            }
        }
    }
    //cout << "I: " << inicial << " lista: ";
    for (int i = 0; i < aux.size(); i++)
    {
        //cout << aux[i] << " ";
        if (temp < aux[i])
        {
            temp = aux[i];
            posicao = i;

            // cout << "Naquele momento: " << tempos[i] << " p: " << i << endl;
        }
    }
    //cout << endl;
    //cout << "Posicao: " << posicao << endl;
    return posicao;
}

bool Pagina::getQuadrosCheio()
{
    int contador = 0;
    for (int i = 0; i < quadros.size(); i++)
    {
        if (quadros[i] != -1)
        {
            contador++;
        }
    }
    if (contador == quadros.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
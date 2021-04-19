#include "pagina.h"

//---- Construtor
Pagina::Pagina()
{
}

//---- Construtor por cópia
Pagina::Pagina(const Pagina &outro)
{

    this->quadros = outro.quadros;
    this->referencias = outro.referencias;
}

//---- Construtor padrão
Pagina::Pagina(int q, vector<int> &r)
{
    for (int i = 0; i < q; i++)
    {
        this->quadros.push_back(-1);
    }
    for (int j = 0; j < r.size(); j++)
    {
        this->referencias.push_back(r[j]);
    }
}

//---- Destrutor padrão
Pagina::~Pagina()
{
}

//---- Altera o valor de quadro especificado
void Pagina::setQuadros(int r, int i)
{
    this->quadros[i] = r;
}

//---- Retorna o valor de quadro especificado
int Pagina::getQuadros(int i)
{
    return this->quadros[i];
}

//---- Retorna o valor de referência especificado
int Pagina::getReferencias(int i)
{
    return this->referencias[i];
}

//---- Retorna o tamanho do vetor de referências
int Pagina::getReferenciasSize()
{
    return this->referencias.size();
}

//---- Retorna o tamanho do vetor de quadros
int Pagina::getQuadrosSize()
{
    return this->quadros.size();
}

//---- Verifica se o valor da referência já está dentro do vetor de quadros
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

//---- Retorna a posição que se encontra a referência dentro do vetor de quadros
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

//---- Zera os quadros e tempos para próxima análise
void Pagina::reiniciaParametros()
{
    for (int i = 0; i < quadros.size(); i++)
    {
        this->quadros[i] = -1;
    }
}

//---- Função que retorna a última referência a ser utilizada dado a posição inicial
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
        for (int i = inicial; i < referencias.size(); i++)
        {
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
    for (int i = 0; i < aux.size(); i++)
    {
        if (temp < aux[i])
        {
            temp = aux[i];
            posicao = i;
        }
    }
    return posicao;
}

//---- Retorna verdadeiro ou falso para condição onde o vetor de quadros está cheio
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

vector<int> Pagina::getVetorQuadros()
{
    return quadros;
}
#include "entrada.h"

//----- Construtor padrão
Entrada::Entrada(string caminho)
{
    // Acha o tamanho ate o . que determina qual o tipo do arquivo
    std::size_t ponto = caminho.find(".") + 1;
    // Se a diferenca do ponto ate o tamanho total for tres e .txt
    if ((caminho.size() - ponto) == 3)
    {
        meuArquivo.open(caminho);
        this->nome = caminho;
    }
    // Se a diferenca for igual a quatro e um arquivo .docx
    else if ((caminho.size() - ponto) == 4)
    {
        string caminhoArrumado;
        // Copia o nome do arquivo para a variavel
        for (int i = 0; i < ponto; i++)
        {
            caminhoArrumado += caminho[i];
        }
        // Adiciona o .txt
        caminhoArrumado += "txt";
        meuArquivo.open(caminhoArrumado);
        this->nome = caminhoArrumado;
    }
    tamanhoArquivo();
}

//----- Destrutor padrão
Entrada::~Entrada()
{
    meuArquivo.close();
}

//----- Retorna o tamanho do arquivo
void Entrada::tamanhoArquivo()
{
    int lin = 0;

    if (meuArquivo.is_open())
    {
        string aux;
        while (getline(meuArquivo, aux))
        {
            lin++;
        }
    }
    else
    {
        cout << "Impossivel Abrir o Arquivo ( " << nome << " )!" << endl;
    }
    setPonteiro();

    this->linhas = lin;
}

//----- Elimina e retorna o marcador para posição inicial do arquivo
void Entrada::setPonteiro()
{
    meuArquivo.clear();
    meuArquivo.seekg(0);
}

//----- Retorna o arquivo em forma de vetor
void Entrada::retornaArquivo(vector<int> &dados)
{
    if (meuArquivo.is_open())
    {
        string aux;
        while (getline(meuArquivo, aux))
        {
            dados[stoi(aux)];
            cout << stoi(aux) << endl;
        }
    }
    else
    {
        cout << "Impossivel Abrir o Arquivo ( " << nome << " )!" << endl;
    }
    setPonteiro();
}

//----- Imprime os dados de um vetor
void Entrada::imprimiDados(vector<int> &dados)
{
    for (auto i : dados)
    {
        cout << i << endl;
    }
    cout << endl;
}

// Imprime os dados do arquivo
void Entrada::imprimiArquivo()
{
    for (int i = 0; i < dadosCentral.size(); i++)
    {
        cout << dadosCentral[i] << endl;
    }
    cout << "---" << endl;
    cout << "N° de referencias: " << linhas;
    cout << endl;
    cout << endl;
}

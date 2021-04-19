#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

using namespace std;

class Pagina
{
private:
    vector<int> quadros;     // Simula os quadros
    vector<int> referencias; // Armazena todas as referências que foram retiradas do arquivo .txt especificado

public:
    Pagina();                      // Construtor
    Pagina(const Pagina &outro);   // Construtor por cópia
    Pagina(int q, vector<int> &r); // Construtor padrão
    ~Pagina();                     // Destrutor padrão

    void setQuadros(int r, int i);                  // Altera o valor de quadro especificado
    int getQuadros(int i);                          // Retorna o valor de quadro especificado
    int getReferencias(int i);                      // Retorna o valor de referência especificado
    int getReferenciasSize();                       // Retorna o tamanho do vetor de referências
    int getQuadrosSize();                           // Retorna o tamanho do vetor de quadros
    bool verificaValorDeReferenciaEmQuadros(int i); // Verifica se o valor da referência já está dentro do vetor de quadros
    int getPosicaoDeReferenciaEmQuadros(int i);     // Retorna a posição que se encontra a referência dentro do vetor de quadros
    void reiniciaParametros();                      // Zera os quadros e tempos para próxima análise
    int getMaiorDiferenca(int inicial);             // Função que retorna a última referência a ser utilizada dado a posição inicial
    bool getQuadrosCheio();                         // Retorna verdadeiro ou falso para condição onde o vetor de quadros está cheio
    vector<int> getVetorQuadros();                  // Retorna os quadros
};

#endif

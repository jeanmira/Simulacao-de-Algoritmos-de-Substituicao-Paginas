#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Pagina
{
private:
    vector<int> quadros;
    vector<int> tempos;
    vector<int> referencias;

public:
    Pagina();                      // Construtor
    Pagina(const Pagina &outro);   // Construtor por cópia
    Pagina(int q, vector<int> &r); // Construtor padrão
    ~Pagina();                     // Destrutor padrão

    void setQuadros(int r, int i);
    void setTempos(int r, int i);
    int getTempos(int i);
    int getQuadros(int i);
    int getReferencias(int i);
    int getReferenciasSize();
    int getQuadrosSize();
    int getPosicaoMenorTempo();
    bool verificaValorDeReferenciaEmQuadros(int i);
    int getPosicaoDeReferenciaEmQuadros(int i);
    void reiniciaParametros();
    int getMaiorDiferenca(int inicial);
    bool getQuadrosCheio();
};

#endif
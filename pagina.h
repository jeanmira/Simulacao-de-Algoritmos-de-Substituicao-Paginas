#ifndef PAGINA_H
#define PAGINA_H

#include <string>
#include <vector>

using namespace std;

class Pagina
{
private:
    vector<int> quadros;
    vector<int> referencias;

public:
    Pagina();
    Pagina(const Pagina &outro);   // Construtor por cópia
    Pagina(int q, vector<int> &r); // Construtor padrão
    ~Pagina();                     // Destrutor padrão

    int getQuadros(int i);
    int getReferencias(int i);
    int getReferenciasSize();
    int getQuadrosSize();
};

#endif
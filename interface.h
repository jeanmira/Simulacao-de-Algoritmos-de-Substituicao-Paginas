#include <SFML/Graphics.hpp>
#include <vector>

#define INTERFACE 1
#define DELAY 1

using namespace std;

class Interface
{
private:
    sf::RenderWindow tela;
    sf::Font font;
    vector<sf::Text> text;
    vector<sf::Text> text_Quadros;
    vector<int> mem1_Quadros;
    vector<int> mem2_Quadros;
    vector<int> mem3_Quadros;
    vector<int> mem4_Quadros;
    vector<int> mem5_Quadros;
    vector<int> mem6_Quadros;
    vector<int> mem7_Quadros;
    vector<sf::Text> text_Ref;
    sf::Event event;
    int n_quadros;

public:
    Interface();
    void imprime_Interface(vector<int> quadros, int ref);
    void setNumeroQuadros(int n_quadros, string sub);
};
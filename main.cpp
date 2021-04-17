#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "pagina.h"
#include "substituicao.h"

using namespace std;

int main(int argc, char *argv[])
{
    vector<int> dados; // Vetor que contém os valores das referências

    int entrada = 0, quadros = 0, valorFifo = 0, valorLru = 0, valorOpt = 0;

    // Armazena os dados inseridos pelo usuário
    quadros = atoi(argv[1]); // Armazena a quantidade de quadros
    while ((!feof(stdin)))
    {
        scanf("%d\n", &entrada);
        dados.push_back(entrada); // Armazena a referências de acordo com o arquivo solicitado
    }

    Pagina p1(quadros, dados); // Cria as páginas e os quadros
    cout << quadros << " quadros" << endl;
    cout << dados.size() << " refs" << endl;

    Substituicao init(p1); // Inicia o algoritmo de substituição e insere os dados das páginas

    valorFifo = init.fifo(); // Análise do método de substituição de página First In, First Out (FIFO)
    valorLru = init.lru();   // Análise do método de substituição de página Least Recently Used (LRU)
    valorOpt = init.opt();   // Analise do método de substituição de página Algoritmo Ótimo (OPT)

    //INTERFACE------------------------------------------------------------------

    sf::RenderWindow tela(sf::VideoMode(480, 480), "Algoritimo de Substituição");

    sf::Font font;
    sf::Text text0, text1, text2, text3, text4, text5, text6, text7, text8, text9;
    font.loadFromFile("arial.ttf");

    text0.setFont(font);
    text0.setString("Quadros: " + to_string(quadros));
    text0.setPosition(sf::Vector2f(100, 155));
    text0.setCharacterSize(24);
    text0.setFillColor(sf::Color::Red);
    text0.setStyle(sf::Text::Bold);

    text1.setFont(font);
    text1.setString("Referencias: " + to_string(dados.size()));
    text1.setPosition(sf::Vector2f(100, 180));
    text1.setCharacterSize(24);
    text1.setFillColor(sf::Color::Red);
    text1.setStyle(sf::Text::Bold);

    text2.setFont(font);
    text2.setString("FIFO: " + to_string(valorFifo));
    text2.setPosition(sf::Vector2f(100, 205));
    text2.setCharacterSize(24);
    text2.setFillColor(sf::Color::Red);
    text2.setStyle(sf::Text::Bold);

    text3.setFont(font);
    text3.setString("LRU: " + to_string(valorLru));
    text3.setPosition(sf::Vector2f(100, 230));
    text3.setCharacterSize(24);
    text3.setFillColor(sf::Color::Red);
    text3.setStyle(sf::Text::Bold);

    text4.setFont(font);
    text4.setString("OPT: " + to_string(valorOpt));
    text4.setPosition(sf::Vector2f(100, 255));
    text4.setCharacterSize(24);
    text4.setFillColor(sf::Color::Red);
    text4.setStyle(sf::Text::Bold);

    while (tela.isOpen())
    {
        sf::Event event;
        while (tela.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                tela.close();
        }

        tela.clear();
        tela.draw(text0);
        tela.draw(text1);
        tela.draw(text2);
        tela.draw(text3);
        tela.draw(text4);
        tela.display();
    }

    return 0;
}

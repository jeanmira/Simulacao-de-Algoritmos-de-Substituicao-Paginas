#include "interface.h"

Interface::Interface()
{
}

void Interface::imprime_Interface(vector<int> quadros, int ref)
{

    while (tela.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            tela.close();
    }
    mem7_Quadros = mem6_Quadros;
    mem6_Quadros = mem5_Quadros;
    mem5_Quadros = mem4_Quadros;
    mem4_Quadros = mem3_Quadros;
    mem3_Quadros = mem2_Quadros;
    mem2_Quadros = mem1_Quadros;
    mem1_Quadros = quadros;

    tela.clear();

    for (int i = 0; i < 8; i++)
    {
        text_Ref[i].setString("Ref(" + to_string(ref - i) + "):");
    }

    for (int i = 0; i < n_quadros; i++)
    {
        text_Quadros[i].setString("Quadro(" + to_string(i) + "):");
        text[i].setPosition(sf::Vector2f(135, 30 + 25 * i));
        text[i].setString(to_string(quadros[i]));
        tela.draw(text[i]);
        text[i].setPosition(sf::Vector2f(285, 30 + 25 * i));
        text[i].setString(to_string(mem1_Quadros[i]));
        tela.draw(text[i]);
        text[i].setPosition(sf::Vector2f(435, 30 + 25 * i));
        text[i].setString(to_string(mem2_Quadros[i]));
        tela.draw(text[i]);
        text[i].setPosition(sf::Vector2f(585, 30 + 25 * i));
        text[i].setString(to_string(mem3_Quadros[i]));
        tela.draw(text[i]);
        text[i].setPosition(sf::Vector2f(735, 30 + 25 * i));
        text[i].setString(to_string(mem4_Quadros[i]));
        tela.draw(text[i]);
        text[i].setPosition(sf::Vector2f(885, 30 + 25 * i));
        text[i].setString(to_string(mem5_Quadros[i]));
        tela.draw(text[i]);
        text[i].setPosition(sf::Vector2f(1035, 30 + 25 * i));
        text[i].setString(to_string(mem6_Quadros[i]));
        tela.draw(text[i]);
        text[i].setPosition(sf::Vector2f(1185, 30 + 25 * i));
        text[i].setString(to_string(mem7_Quadros[i]));
        tela.draw(text[i]);
    }

    for (int i = 0; i < n_quadros; i++)
    {
        tela.draw(text_Quadros[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        tela.draw(text_Ref[i]);
    }

    tela.display();
}

void Interface::setNumeroQuadros(int n_quadros, string sub)
{
    this->n_quadros = n_quadros;

    font.loadFromFile("arial.ttf");
    tela.create(sf::VideoMode(1350, 850), sub);

    sf::Text text_Aux;
    if (n_quadros < 32)
    {
        for (int i = 0; i < n_quadros; i++)
        {
            text.push_back(text_Aux);
            text[i].setFont(font);
            text[i].setPosition(sf::Vector2f(135, 30 + 25 * i));
            text[i].setCharacterSize(20);
            text[i].setFillColor(sf::Color::Green);
            text[i].setStyle(sf::Text::Bold);
            text_Quadros.push_back(text_Aux);
            text_Quadros[i].setFont(font);
            text_Quadros[i].setPosition(sf::Vector2f(0, 30 + 25 * i));
            text_Quadros[i].setCharacterSize(20);
            text_Quadros[i].setFillColor(sf::Color::Red);
            text_Quadros[i].setStyle(sf::Text::Bold);
            mem1_Quadros.push_back(-1);
            mem2_Quadros.push_back(-1);
            mem3_Quadros.push_back(-1);
            mem4_Quadros.push_back(-1);
            mem5_Quadros.push_back(-1);
            mem6_Quadros.push_back(-1);
            mem7_Quadros.push_back(-1);
        }
    }
    else
    {
        n_quadros = 32;
        for (int i = 0; i < n_quadros; i++)
        {
            text.push_back(text_Aux);
            text[i].setFont(font);
            text[i].setPosition(sf::Vector2f(135, 30 + 25 * i));
            text[i].setCharacterSize(20);
            text[i].setFillColor(sf::Color::Green);
            text[i].setStyle(sf::Text::Bold);
            text_Quadros.push_back(text_Aux);
            text_Quadros[i].setFont(font);
            text_Quadros[i].setPosition(sf::Vector2f(0, 30 + 25 * i));
            text_Quadros[i].setCharacterSize(20);
            text_Quadros[i].setFillColor(sf::Color::Red);
            text_Quadros[i].setStyle(sf::Text::Bold);
            mem1_Quadros.push_back(-1);
            mem2_Quadros.push_back(-1);
            mem3_Quadros.push_back(-1);
            mem4_Quadros.push_back(-1);
            mem5_Quadros.push_back(-1);
            mem6_Quadros.push_back(-1);
            mem7_Quadros.push_back(-1);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        text_Ref.push_back(text_Aux);
        text_Ref[i].setFont(font);
        text_Ref[i].setPosition(sf::Vector2f(120 + i * 150, 0));
        text_Ref[i].setCharacterSize(20);
        text_Ref[i].setFillColor(sf::Color::Blue);
        text_Ref[i].setStyle(sf::Text::Bold);
    }
}

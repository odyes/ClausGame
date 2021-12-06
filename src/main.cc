#include <iostream>
#include <ctime>
#include <stdlib.h>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Character.hh"
#include "Gift.hh"

int main()
{    
    std::srand((unsigned)std::time(0));

    // Inicialización de la ventana-----ancho, alto                  
    sf::RenderWindow window(sf::VideoMode(800,600), "Final Game");
    window.setFramerateLimit(60);

    sf::Font font;
    font.loadFromFile("assets/fonts/SweaterStitch.ttf");
    sf::Text text;

    text.setFillColor(sf::Color::Black);
    text.setFont(font);

    Character santa;
    Gift gift;
    gift.respawn();
    
    int score=0;

    sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("assets/sprites/snow.jpg");

    image.setTexture(tex);


    //Game lop (update del juego)
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //CMD- ejecutar los comandos

       
        //Update- Actualiza los estados del juego
        santa.update();

        if(santa.isCollision(gift))
        {
            gift.respawn();
            score++;
        }
        text.setString(" SCORE: "+std::to_string(score));

        window.clear();

        window.draw(image);
        window.draw(santa);
        window.draw(gift);
        window.draw(text);
        
        //Draw
        //Display-flip
        window.display();
        
    }
    //Liberacion del juego


    return 0;
}
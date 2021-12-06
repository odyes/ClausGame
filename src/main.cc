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

    //Fuente
    sf::Font font;
    font.loadFromFile("assets/fonts/SweaterStitch.ttf");
    sf::Text text;
    //Color de fuente
    text.setFillColor(sf::Color::Black);
    text.setFont(font);

    //Declaración
    Character santa;
    Gift gift;
    gift.respawn();
    
    int score=0;

    //Fondo
    sf::Sprite image;
    sf::Texture tex;
    tex.loadFromFile("assets/sprites/snow.jpg");
    image.setTexture(tex);

    //Sonido
    sf::SoundBuffer buffer;
    buffer.loadFromFile("assets/audio/ring.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);


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
            sound.play();
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
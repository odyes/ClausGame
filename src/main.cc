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
#include "Enemy.hh"

int main()
{    
    std::srand((unsigned)std::time(0));

    // Inicialización de la ventana-----ancho, alto                  
    sf::RenderWindow window(sf::VideoMode(800,600), "Claus Game");
    window.setFramerateLimit(60);

    //icon
    sf::Image icon;
    if(!icon.loadFromFile("assets/sprites/icon.png"))
    {
        return -1;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Fuente
    sf::Font font;
    font.loadFromFile("assets/fonts/SweaterStitch.ttf");

    sf::Text text, lifesText, textMessage;
    text.setFont(font);
    lifesText.setFont(font);
    textMessage.setFont(font);

    lifesText.setPosition({0, 50});
    textMessage.setPosition({150,150});

    //Color de fuente
    text.setFillColor(sf::Color::Black);
    lifesText.setFillColor(sf::Color::Black);
    textMessage.setFillColor(sf::Color::Red);

    //Declaración
    Character santa;
    Gift gift;
    gift.respawn();

    Enemy enemy;
    enemy.respawn();

    int score=0;
    int lifes=3;

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
    
    sf::Music music;
    music.openFromFile("assets/audio/music.ogg");
    music.setVolume(5);
    music.play();

    /*sf::SoundBuffer* musicBuffer{new sf::SoundBuffer()};
    sf::Sound* musicSound{new sf::Sound()};
    musicBuffer->loadFromFile("assets/audio/music.ogg");
    musicSound->setBuffer(*musicBuffer);*/

    //Game loop (update del juego)
    while(window.isOpen())
    {

        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //CMD- ejecutar los comandos

        if(lifes>0)
        {
            //Update- Actualiza los estados del juego
            enemy.update();
            santa.cmd();
            santa.update();

            if(santa.isCollision(gift))
            {
                gift.respawn(); //Se vuelve a dibujar en otro lado
                score++;
                sound.play();
            }
        
            //Colisiona con el enemigo
            if(santa.isCollision(enemy))
            {
                santa.hited();
                enemy.walloper();

                lifes--;
                //enemy.respawn();
            }
            textMessage.setString("");
        }
        else 
        {
            textMessage.setString("PRESIONA ENTER PARA CONTINUAR");
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                lifes=3;
                score=0;
                enemy.respawn();
            }
        }


        text.setString(" SCORE: "+std::to_string(score));
        lifesText.setString(" LIFES: "+ std::to_string(lifes));

        window.clear();
        
        //Draw
        window.draw(image);
        window.draw(santa);
        window.draw(gift);
        window.draw(text);
        window.draw(lifesText);
        window.draw(enemy);
        window.draw(textMessage);
        
    
        //Display-flip
        window.display();
        
    }
    //Liberacion del juego


    return 0;
}
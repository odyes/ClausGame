#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.hh"
#include <SFML/Audio.hpp>

class Enemy: public sf::Drawable, public Collisionable
{
    private:
      sf::Sprite _sprite;
      sf::Texture _texture;
      int _timeRespawn;

      sf::Sound _channel;
      sf::SoundBuffer _laughter;
      sf::Vector2f _newPosition;
        
    public:
      Enemy();
      void update();
      void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
      void respawn(); //Reposiciona el item
      void walloper();

      sf::FloatRect getBounds() const override; //el metodo es constante
};
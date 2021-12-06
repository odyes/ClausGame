#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.hh"

class Character: public sf::Drawable, public Collisionable
{
    private:
      sf::Sprite _sprite;
      sf::Texture _texture;
      sf::Vector2f _velocity;
    
    public:
    Character();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override;
};
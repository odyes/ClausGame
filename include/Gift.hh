#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.hh"

class Gift : public sf::Drawable, public Collisionable
{
private:
   sf::Sprite _sprite;
   sf::Texture _texture;
public:
    Gift();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    void respawn(); //Reposiciona el item
    sf::FloatRect getBounds() const override; //el metodo es constante
};



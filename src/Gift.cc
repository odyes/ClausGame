#include <stdlib.h>

#include "Gift.hh"

Gift::Gift()
{
    _texture.loadFromFile("assets/sprites/gift.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);

}

void Gift::update()
{

}

void Gift::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}

//Random
void Gift::respawn()
{
    _sprite.setPosition(std::rand()%700+ _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
}

sf::FloatRect Gift::getBounds() const
{
    return _sprite.getGlobalBounds();
}
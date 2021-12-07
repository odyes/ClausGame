#include <stdlib.h>
#include "Enemy.hh"


Enemy::Enemy()
{
    _texture.loadFromFile("assets/sprites/enemy.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);

    _laughter.loadFromFile("assets/audio/laughter.ogg");
    _channel.setBuffer(_laughter);
}

void Enemy::update()
{
    _timeRespawn--;

    /*if (_timeRespawn<0)
    {
        _timeRespawn=60*3;
       // _newPosition={std::rand()%700+ _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height };
    }*/


    if(_newPosition.x > _sprite.getPosition().x)
    {
        _sprite.move(5, 0);
    }
    
    if(_newPosition.x < _sprite.getPosition().x)
    {
        _sprite.move(-5, 0);
    }
    
    if(_newPosition.y > _sprite.getPosition().y)
    {
        _sprite.move(0, 5);
    }

    if(_newPosition.y < _sprite.getPosition().y)
    {
        _sprite.move(0, -5);
    }

    //Corregir
    if(std::abs(_newPosition.x - _sprite.getPosition().x)<=5)
    {
        _sprite.setPosition(_newPosition.x, _sprite.getPosition().y);
        _newPosition={std::rand()%700+ _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height };
    }

     if(std::abs(_newPosition.y - _sprite.getPosition().y)<=5)
    {
        _sprite.setPosition(_newPosition.x, _sprite.getPosition().y);
        _newPosition={std::rand()%700+ _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height };
    }
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    target.draw(_sprite, states);
}

//Random
void Enemy::respawn()
{
    _sprite.setPosition(std::rand()%700+ _sprite.getGlobalBounds().width, std::rand()%500 + _sprite.getGlobalBounds().height);
    _timeRespawn=60*3;
}

void Enemy::walloper()
{
    respawn();
    _channel.play();
}

sf::FloatRect Enemy::getBounds() const
{
    return _sprite.getGlobalBounds();
}

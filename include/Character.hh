#pragma once
#include <SFML/Graphics.hpp>
#include "Colisionable.hh"

enum class CharacterState
      {
         Idle=0,
         Move
      };


class Character: public sf::Drawable, public Collisionable
{
    private:
      sf::Sprite _sprite;
      sf::Texture _texture;
      sf::Vector2f _velocity;

      sf::Vector2f _movePosition={0,0};

      float _frame;
      CharacterState _state= CharacterState::Idle;
    public:
    Character();
    void cmd();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states)const override;
    sf::FloatRect getBounds() const override;
    void hited();
};
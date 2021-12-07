#include "Character.hh"

Character::Character()
{
    _frame=0;
    _velocity = {4, 4};
    _texture.loadFromFile("assets/sprites/santa2.png");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({1, 86, 55 , 74});
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height);
}

void Character::cmd()
{

    _movePosition={0,0};
    _state=CharacterState::Idle;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            _movePosition.y= -_velocity.y;
            _state=CharacterState::Move;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _movePosition.x= -_velocity.x;
            _state=CharacterState::Move;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            _movePosition.y= _velocity.y;
            _state=CharacterState::Move;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _movePosition.x= _velocity.x;
            _state=CharacterState::Move;
        }
}

void Character::update()
{
   /* _velocity= { 0,0 };

   // _frame+= 0.2;
//    if(_frame>=3)
    //{
        //_frame=0;
    //}

//    _sprite.setTextureRect({1+int(_frame)*55, 86, 50 , 74});
 
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            _velocity.y = -4;
            _sprite.setTextureRect({1+int(_frame)*55, 86, 50 , 74});
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            _velocity.x = -4;
            _sprite.setTextureRect({1+int(_frame)*55, 86, 50 , 74});
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            _velocity.y = 4;
            _sprite.setTextureRect({1+int(_frame)*55, 86, 50 , 74});
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            _velocity.x = 4;
            //_sprite.setTextureRect({1+int(_frame)*55, 86, 50 , 74});
        }*/

        switch (_state)
        {
        case CharacterState::Idle:
            _sprite.setTextureRect({56, 86, 50 , 74});
            
            break;
        case CharacterState::Move:
              _frame+= 0.2;
              if(_frame>=3)
              {
                _frame=0;
              }

              _sprite.setTextureRect({1+int(_frame)*55, 86, 50 , 74});
              _sprite.move(_movePosition);

              if(_movePosition.x < 0)
              {
                 _sprite.setScale(-1, 1);
              }
              else if (_movePosition.x > 0)
              {
                 _sprite.setScale(1, 1);
              } 
        
            break;
        default:
            break;
        }

        //_sprite.move(_velocity);

        /*if(_velocity.x < 0)
        {
            _sprite.setScale(-1, 1);
        }
        else if (_velocity.x > 0)
        {
            _sprite.setScale(1, 1);
        }*/
        

        //Para que no se salga del cuadro
        if(_sprite.getGlobalBounds().left < 0) 
        {
            _sprite.setPosition(_sprite.getOrigin().x, _sprite.getPosition().y);
        }

        if(_sprite.getGlobalBounds().top < 0) 
        {
            _sprite.setPosition(_sprite.getPosition().x, _sprite.getOrigin().y);
        }

        if(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width > 800) 
        {
           _sprite.setPosition(800- (_sprite.getLocalBounds().width - _sprite.getOrigin().x), _sprite.getPosition().y);
        }

        if(_sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height > 600) 
        {
            _sprite.setPosition(_sprite.getPosition().x, 600+(_sprite.getGlobalBounds().height- _sprite.getOrigin().y));
        }

}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(_sprite, states);
}

sf::FloatRect Character::getBounds() const
{
    return _sprite.getGlobalBounds();
}

void Character::hited()
{
}
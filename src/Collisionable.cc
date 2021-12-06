#include "Colisionable.hh"

//Colisionar
bool Collisionable::isCollision(Collisionable& obj) const
{
    return getBounds().intersects(obj.getBounds());
}
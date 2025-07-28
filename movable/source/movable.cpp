#include "movable.h"
#include <iostream>

bool Coordinates::operator==(const Coordinates& coords) const
{
    return x == coords.x && y == coords.y;
}

void Move::move(std::shared_ptr<IMovable> object)
{
    auto pos = object->getPosition();
    auto velocity = object->getVelocity();

    auto res = pos + velocity;

    object->setPosition(res);
}

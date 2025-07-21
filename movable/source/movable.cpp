#include "movable.h"
#include <iostream>

bool Coordinates::operator==(const Coordinates& coords) const
{
    return x == coords.x && y == coords.y;
}

void Move::move(std::shared_ptr<IMovable> object)
{
    auto pos = object->getPosition();
    auto speed = object->getSpeed();

    auto res = pos + speed;
    std::cerr << "set position " << res << std::endl;

    object->setPosition(res);
}

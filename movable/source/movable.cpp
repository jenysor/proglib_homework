#include "movable.h"

void Move::move(std::shared_ptr<IMovable> object)
{
    auto pos = object->getPosition();
    auto velocity = object->getVelocity();

    auto res = pos + velocity;

    object->setPosition(res);
}

#ifndef PROGLIB_HOMEWORK_MOVABLE_H
#define PROGLIB_HOMEWORK_MOVABLE_H

#include "interfaces.h"
#include <memory>

class Move
{
public:
    Move() = default;

    static void move(std::shared_ptr<IMovable> object);
};

#endif // PROGLIB_HOMEWORK_MOVABLE_H

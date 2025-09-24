#ifndef PROGLIB_HOMEWORK_ROTATING_H
#define PROGLIB_HOMEWORK_ROTATING_H

#include "interfaces.h"
#include <memory>

class Rotate
{
public:
    Rotate() = default;

    static void rotate(std::shared_ptr<IRotating> object);
};

#endif // PROGLIB_HOMEWORK_ROTATING_H

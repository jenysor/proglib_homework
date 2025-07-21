#ifndef PROGLIB_HOMEWORK_ROTATING_H
#define PROGLIB_HOMEWORK_ROTATING_H

#include <memory>

class IRotating
{
public:
    virtual void getRotation()        = 0;
    virtual void getAngularVelocity() = 0;
    virtual void setRotation()        = 0;

    virtual ~IRotating() = default;
};

class Rotate
{
public:
    Rotate() = default;

    static void rotate(std::shared_ptr<IRotating> object);
};

#endif // PROGLIB_HOMEWORK_ROTATING_H

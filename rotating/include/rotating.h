#ifndef PROGLIB_HOMEWORK_ROTATING_H
#define PROGLIB_HOMEWORK_ROTATING_H

#include <memory>

class IRotating
{
public:
    virtual double getRotation() = 0;
    virtual double getAngularVelocity() = 0;
    virtual void setRotation(double rotation) = 0;

    virtual ~IRotating() = default;
};

class Rotate
{
public:
    Rotate() = default;

    static void rotate(std::shared_ptr<IRotating> object);
};

#endif // PROGLIB_HOMEWORK_ROTATING_H

#include "rotating.h"
#include <iostream>

void Rotate::rotate(std::shared_ptr<IRotating> object)
{
     auto pos = object->getRotation();
     auto velocity = object->getAngularVelocity();

     auto res = pos + velocity;
     std::cerr << "set rotation " << res << std::endl;

     object->setRotation(res);
}

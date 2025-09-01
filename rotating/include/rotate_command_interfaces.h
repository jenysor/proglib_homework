#ifndef PROGLIB_HOMEWORK_ROTATE_COMMAND_INTERFACES_H
#define PROGLIB_HOMEWORK_ROTATE_COMMAND_INTERFACES_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IRotateCommandStartable {
public:
    virtual std::shared_ptr<IUObject> getRotatingObject() const = 0;

    virtual int getAngularVelocity() const = 0;

    virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

    virtual ~IRotateCommandStartable() = default;
};

class IRotateCommandEndable {
public:
    virtual std::shared_ptr<IUObject> getRotatingObject() const = 0;

    virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

    virtual ~IRotateCommandEndable() = default;
};

#endif //PROGLIB_HOMEWORK_ROTATE_COMMAND_H

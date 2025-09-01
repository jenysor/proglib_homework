#ifndef PROGLIB_HOMEWORK_MOVE_COMMAND_INTERFACES_H
#define PROGLIB_HOMEWORK_MOVE_COMMAND_INTERFACES_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IMoveCommandStartable {
public:
    virtual std::shared_ptr<IUObject> getMovingObject() const = 0;

    virtual int getVelocity() const = 0;

    virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

    virtual ~IMoveCommandStartable() = default;
};

class IMoveCommandEndable {
public:
    virtual std::shared_ptr<IUObject> getMovingObject() const = 0;

    virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

    virtual ~IMoveCommandEndable() = default;
};

#endif //PROGLIB_HOMEWORK_MOVE_COMMAND_INTERFACES_H

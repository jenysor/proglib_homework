#ifndef PROGLIB_HOMEWORK_MOVE_STARTABLE_H
#define PROGLIB_HOMEWORK_MOVE_STARTABLE_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IMoveCommandStartable {
public:
	[[nodiscard]] virtual std::shared_ptr<IUObject> getMovingObject() const = 0;

	[[nodiscard]] virtual int getVelocity() const = 0;

	[[nodiscard]] virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

	virtual ~IMoveCommandStartable() = default;
};

#endif //PROGLIB_HOMEWORK_MOVE_STARTABLE_H

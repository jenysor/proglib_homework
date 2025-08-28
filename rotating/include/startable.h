#ifndef PROGLIB_HOMEWORK_ROTATE_STARTABLE_H
#define PROGLIB_HOMEWORK_ROTATE_STARTABLE_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IRotateCommandStartable {
public:
	[[nodiscard]] virtual std::shared_ptr<IUObject> getRotatingObject() const = 0;

	[[nodiscard]] virtual int getAngularVelocity() const = 0;

	[[nodiscard]] virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

	virtual ~IRotateCommandStartable() = default;
};

#endif // PROGLIB_HOMEWORK_ROTATE_STARTABLE_H

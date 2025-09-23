#ifndef PROGLIB_HOMEWORK_ROTATE_ENDABLE_H
#define PROGLIB_HOMEWORK_ROTATE_ENDABLE_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IRotateCommandEndable {
public:
	[[nodiscard]] virtual std::shared_ptr<IUObject> getRotatingObject() const = 0;

	[[nodiscard]] virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

	virtual ~IRotateCommandEndable() = default;
};

#endif // PROGLIB_HOMEWORK_ROTATE_ENDABLE_H

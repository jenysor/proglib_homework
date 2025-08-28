#ifndef PROGLIB_HOMEWORK_MOVE_ENDABLE_H
#define PROGLIB_HOMEWORK_MOVE_ENDABLE_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IMoveCommandEndable {
public:
	[[nodiscard]] virtual std::shared_ptr<IUObject> getMovingObject() const = 0;

	[[nodiscard]] virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

	virtual ~IMoveCommandEndable() = default;
};

#endif // PROGLIB_HOMEWORK_MOVE_ENDABLE_H

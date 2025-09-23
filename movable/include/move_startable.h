#ifndef PROGLIB_HOMEWORK_MOVE_STARTABLE_H
#define PROGLIB_HOMEWORK_MOVE_STARTABLE_H

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

class StartMoveCommand : public ICommand {
public:
	explicit StartMoveCommand(std::shared_ptr<IUObject> obj, std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q,
	                 double velocity);

	void execute() override;

private:
	std::shared_ptr<IUObject> movingObject{};
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue{};
	double velocity{0};
};

#endif // PROGLIB_HOMEWORK_MOVE_STARTABLE_H

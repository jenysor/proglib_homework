#ifndef PROGLIB_HOMEWORK_MOVE_STARTABLE_H
#define PROGLIB_HOMEWORK_MOVE_STARTABLE_H

#include "interfaces.h"
#include "adapters.h"
#include "movable.h"
#include <memory>
#include <queue>

class IMoveCommandStartable {
public:
	[[nodiscard]] virtual std::shared_ptr<IUObject> getMovingObject() const = 0;

	[[nodiscard]] virtual int getVelocity() const = 0;

	[[nodiscard]] virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

	virtual ~IMoveCommandStartable() = default;
};

class MoveCommand : public ICommand {
public:
	MoveCommand(std::shared_ptr<IUObject> obj) : movingObject(std::move(obj))
	{}

	void execute() override
	{
		// Move::move(movingObject);
	}
	std::shared_ptr<IUObject> movingObject{};
};

class StartMoveCommand : public ICommand {
public:
	StartMoveCommand(std::shared_ptr<IUObject> obj, std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q) :
	    movingObject(std::move(obj)), queue(std::move(q))
	{}

	void execute() override
	{
		VelocityAdapter adapter(movingObject);
		adapter.setVelocity(1);

		queue->push(std::make_shared<MoveCommand>(movingObject));
	}

private:
	std::shared_ptr<IUObject> movingObject{};
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue{};
};

#endif // PROGLIB_HOMEWORK_MOVE_STARTABLE_H

#include "startable.h"
#include "adapters.h"
#include "move_command.h"

StartMoveCommand::StartMoveCommand(std::shared_ptr<IUObject> obj, std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q,
		double velocity) :
		movingObject(std::move(obj)), queue(std::move(q)), velocity(velocity)
{}

void StartMoveCommand::execute()
{
	VelocityAdapter adapter(movingObject);
	adapter.setVelocity(velocity);

	queue->push(std::make_shared<MoveCommand>(movingObject));
}
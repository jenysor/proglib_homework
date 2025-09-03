#include "endable.h"
#include "adapters.h"
#include "move_command.h"

EndMoveCommand::EndMoveCommand(std::shared_ptr<IUObject> obj,
                               std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q) :
    movingObject(obj), queue(q)
{}

void EndMoveCommand::execute()
{
	VelocityAdapter adapter(movingObject);
	adapter.removeVelocity();

	auto size = queue->size();
	std::queue<std::shared_ptr<ICommand>> newQueue;

	for(size_t num = 0; num < size; ++num) {
		const auto& command = queue->front();

		if(!dynamic_cast<MoveCommand*>(command.get())) {
			newQueue.push(command);
		}

		queue->pop();
	}

	*queue = newQueue;
}

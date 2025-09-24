#include "rotate_endable.h"
#include "adapters.h"
#include "rotate_command.h"

EndRotateCommand::EndRotateCommand(std::shared_ptr<IUObject> obj,
							   std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q) :
	rotatingObject(obj), queue(q)
{}

void EndRotateCommand::execute()
{
	AngularVelocityAdapter adapter(rotatingObject);
	adapter.removeAngularVelocity();

	auto size = queue->size();
	std::queue<std::shared_ptr<ICommand>> newQueue;

	for(size_t num = 0; num < size; ++num) {
		const auto& command = queue->front();

		if(!dynamic_cast<RotateCommand*>(command.get())) {
			newQueue.push(command);
		}

		queue->pop();
	}

	*queue = newQueue;
}

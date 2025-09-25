#include "order_handler.h"
#include "move_startable.h"
#include "adapters.h"

StartMoveHandler::StartMoveHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue) :
    queue(std::move(queue))
{}

void StartMoveHandler::handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const
{
	VelocityAdapter adapter(order);
	auto velocity = adapter.getVelocity();

	queue->push(std::make_shared<StartMoveCommand>(object, queue, velocity));
}

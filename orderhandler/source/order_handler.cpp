#include "order_handler.h"
#include "move_startable.h"
#include "move_endable.h"
#include "rotate_startable.h"
#include "rotate_endable.h"
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

EndMoveHandler::EndMoveHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue) : queue(std::move(queue))
{}

void EndMoveHandler::handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const
{
	queue->push(std::make_shared<EndMoveCommand>(object, queue));
}

StartRotateHandler::StartRotateHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue) :
    queue(std::move(queue))
{}

void StartRotateHandler::handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const
{
	AngularVelocityAdapter adapter(order);
	auto angVelocity = adapter.getAngularVelocity();

	queue->push(std::make_shared<StartRotateCommand>(object, queue, angVelocity));
}

EndRotateHandler::EndRotateHandler(std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue) :
    queue(std::move(queue))
{}

void EndRotateHandler::handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const
{
	queue->push(std::make_shared<EndRotateCommand>(object, queue));
}

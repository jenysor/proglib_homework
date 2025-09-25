#include "order_handler_pool.h"
#include "adapters.h"

void OrderHandlerPool::registerHandler(const std::string& action, std::shared_ptr<IOrderHandler> handler)
{
	handlers[action] = std::move(handler);
}

void OrderHandlerPool::handleOrder(std::shared_ptr<IUObject> order, std::shared_ptr<IUObject> object) const
{
	ActionAdapter adapter(order);
	auto action = adapter.getAction();

	if(handlers.find(action) != handlers.end()) {
		handlers.at(action)->handleOrder(order, object);
	}
}

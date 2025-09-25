#include "order_handler_pool.h"

void OrderHandlerPool::registerHandler(const std::string& action, std::shared_ptr<IOrderHandler> handler)
{
	handlers[action] = std::move(handler);
}

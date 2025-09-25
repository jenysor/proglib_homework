#ifndef PROGLIB_HOMEWORK_ORDER_HANDLER_POOL_H
#define PROGLIB_HOMEWORK_ORDER_HANDLER_POOL_H

#include "order_handler.h"
#include <map>

class OrderHandlerPool {
public:
	void registerHandler(const std::string& action, std::shared_ptr<IOrderHandler> handler);

private:
	std::map<std::string, std::shared_ptr<IOrderHandler>> handlers;
};

#endif //PROGLIB_HOMEWORK_ORDER_HANDLER_POOL_H

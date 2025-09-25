#include "order_handler_pool.h"
#include "gtest/gtest.h"

class TestOrderHandler : public testing::Test {
public:
	TestOrderHandler()
	{
		handlerPool = std::make_unique<OrderHandlerPool>();
		queue       = std::make_shared<std::queue<std::shared_ptr<ICommand>>>();
	}

	std::unique_ptr<OrderHandlerPool> handlerPool;
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

TEST_F(TestOrderHandler, OrderHandler_HandleStartMoveCommand_Success)
{
	handlerPool->registerHandler("startMove", std::make_shared<StartMoveHandler>(queue));
}
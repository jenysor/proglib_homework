#include "move_startable.h"
#include "order_handler_pool.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockUObject : public IUObject {
public:
	MOCK_METHOD(void, setProperty, (const std::string&, const std::string&), (override));
	MOCK_METHOD(std::string, getProperty, (const std::string&), (const override));
	MOCK_METHOD(bool, hasProperty, (const std::string&), (const override));
	MOCK_METHOD(void, removeProperty, (const std::string&), (override));
};

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
	std::string actionProperty{"action"};
	std::string action{"startMove"};

	handlerPool->registerHandler(action, std::make_shared<StartMoveHandler>(queue));

	std::string velocityProperty{"velocity"};
	double velocity{11.4};

	auto order  = std::make_shared<MockUObject>();
	auto object = std::make_shared<MockUObject>();

	EXPECT_CALL(*order, hasProperty(actionProperty)).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*order, getProperty(actionProperty)).WillOnce(testing::Invoke([action]() {
		return action;
	}));

	EXPECT_CALL(*order, hasProperty(velocityProperty)).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*order, getProperty(velocityProperty)).WillOnce(testing::Invoke([velocity]() {
		return std::to_string(velocity);
	}));

	handlerPool->handleOrder(order, object);

	ASSERT_TRUE(queue->size() == 1);
	ASSERT_TRUE(dynamic_cast<StartMoveCommand*>(queue->front().get()));
}
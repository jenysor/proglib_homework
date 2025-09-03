#include "startable.h"
#include "endable.h"
#include "move_command.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockUObject : public IUObject {
public:
	MOCK_METHOD(void, setProperty, (const std::string&, const std::string&), (override));
	MOCK_METHOD(std::string, getProperty, (const std::string&), (const override));
	MOCK_METHOD(bool, hasProperty, (const std::string&), (const override));
	MOCK_METHOD(void, removeProperty, (const std::string&), (override));
};

class TestMoveCommand : public testing::Test {
public:
	TestMoveCommand()
	{
		queue = std::make_shared<std::queue<std::shared_ptr<ICommand>>>();
	}

	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

TEST_F(TestMoveCommand, MoveCommand_Execute_Success)
{
	double position{5.1};
	double velocity{7.0};
	double etalonPosition = position + velocity;

	auto object = std::make_shared<MockUObject>();

	MoveCommand command(object);

	EXPECT_CALL(*object, hasProperty("position")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, hasProperty("velocity")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("position")).WillOnce(testing::Invoke([position]() {
		return std::to_string(position);
	}));

	EXPECT_CALL(*object, getProperty("velocity")).WillOnce(testing::Invoke([velocity]() {
		return std::to_string(velocity);
	}));

	EXPECT_CALL(*object, setProperty("position", std::to_string(etalonPosition)));

	command.execute();
}

TEST_F(TestMoveCommand, StartMoveCommand_Execute_Success)
{
	std::string property{"velocity"};
	double value{11.5};

	auto object = std::make_shared<MockUObject>();

	StartMoveCommand command(object, queue, value);

	EXPECT_CALL(*object, setProperty(property, std::to_string(value)));

	command.execute();

	ASSERT_TRUE(queue->size() == 1);
	ASSERT_TRUE(dynamic_cast<MoveCommand*>(queue->front().get()));
}

TEST_F(TestMoveCommand, EndMoveCommand_Execute_Success)
{
	std::string property{"velocity"};

	auto object = std::make_shared<MockUObject>();

	queue->push(std::make_shared<MoveCommand>(object));

	EndMoveCommand command(object, queue);

	EXPECT_CALL(*object, removeProperty(property));

	command.execute();

	ASSERT_TRUE(queue->empty());
}

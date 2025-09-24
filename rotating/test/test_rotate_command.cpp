#include "rotate_startable.h"
#include "rotate_endable.h"
#include "rotate_command.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class MockUObject : public IUObject {
public:
	MOCK_METHOD(void, setProperty, (const std::string&, const std::string&), (override));
	MOCK_METHOD(std::string, getProperty, (const std::string&), (const override));
	MOCK_METHOD(bool, hasProperty, (const std::string&), (const override));
	MOCK_METHOD(void, removeProperty, (const std::string&), (override));
};

class MockCommand : public ICommand {
public:
	MOCK_METHOD(void, execute, (), (override));
};

class TestRotateCommand : public testing::Test {
public:
	TestRotateCommand()
	{
		queue = std::make_shared<std::queue<std::shared_ptr<ICommand>>>();
	}

	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue;
};

TEST_F(TestRotateCommand, RotateCommand_Execute_Success)
{
	double rotation{5.1};
	double angularVelocity{7.0};
	double etalonRotation = rotation + angularVelocity;

	auto object = std::make_shared<MockUObject>();

	RotateCommand command(object);

	EXPECT_CALL(*object, hasProperty("rotation")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, hasProperty("angularVelocity")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("rotation")).WillOnce(testing::Invoke([rotation]() {
		return std::to_string(rotation);
	}));

	EXPECT_CALL(*object, getProperty("angularVelocity")).WillOnce(testing::Invoke([angularVelocity]() {
		return std::to_string(angularVelocity);
	}));

	EXPECT_CALL(*object, setProperty("rotation", std::to_string(etalonRotation)));

	command.execute();
}

TEST_F(TestRotateCommand, StartRotateCommand_Execute_Success)
{
	std::string property{"angularVelocity"};
	double value{11.5};

	auto object = std::make_shared<MockUObject>();

	StartRotateCommand command(object, queue, value);

	EXPECT_CALL(*object, setProperty(property, std::to_string(value)));

	command.execute();

	ASSERT_TRUE(queue->size() == 1);
	ASSERT_TRUE(dynamic_cast<RotateCommand*>(queue->front().get()));
}

TEST_F(TestRotateCommand, EndRotateCommand_Execute_Success)
{
	std::string property{"angularVelocity"};

	auto object = std::make_shared<MockUObject>();

	queue->push(std::make_shared<RotateCommand>(object));

	EndRotateCommand command(object, queue);

	EXPECT_CALL(*object, removeProperty(property));

	command.execute();

	ASSERT_TRUE(queue->empty());
}

TEST_F(TestRotateCommand, EndRotateCommand_Execute_EmptyQueue)
{
	std::string property{"angularVelocity"};

	auto object = std::make_shared<MockUObject>();

	EndRotateCommand command(object, queue);

	EXPECT_CALL(*object, removeProperty(property));

	command.execute();

	ASSERT_TRUE(queue->empty());
}

TEST_F(TestRotateCommand, EndRotateCommand_Execute_NotEmptyQueue)
{
	std::string property{"angularVelocity"};

	auto object = std::make_shared<MockUObject>();

	queue->push(std::make_shared<MockCommand>());
	queue->push(std::make_shared<MockCommand>());
	queue->push(std::make_shared<RotateCommand>(object));
	queue->push(std::make_shared<MockCommand>());

	EndRotateCommand command(object, queue);

	EXPECT_CALL(*object, removeProperty(property));

	command.execute();

	ASSERT_TRUE(queue->size() == 3);
}
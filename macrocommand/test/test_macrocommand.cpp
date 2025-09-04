#include "macrocommand.h"
#include "fuelcommands.h"
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

class MockCommand : public ICommand {
public:
	MOCK_METHOD(void, execute, (), (override));
};

TEST(MacroCommand, MacroCommand_Execute_Success)
{
	auto cmds = std::make_shared<std::list<std::shared_ptr<ICommand>>>();

	auto command0 = std::make_shared<MockCommand>();
	auto command1 = std::make_shared<MockCommand>();
	auto command2 = std::make_shared<MockCommand>();

	EXPECT_CALL(*command0, execute());
	EXPECT_CALL(*command1, execute());
	EXPECT_CALL(*command2, execute());

	cmds->push_back(command0);
	cmds->push_back(command1);
	cmds->push_back(command2);

	MacroCommand macroCommand(cmds);

	macroCommand.execute();
}

TEST(MacroCommand, MacroCommand_Execute_ExceptionCommand1)
{
	auto cmds = std::make_shared<std::list<std::shared_ptr<ICommand>>>();

	auto command0 = std::make_shared<MockCommand>();
	auto command1 = std::make_shared<MockCommand>();
	auto command2 = std::make_shared<MockCommand>();

	EXPECT_CALL(*command0, execute());

	EXPECT_CALL(*command1, execute()).WillOnce(testing::Invoke([]() {
		throw CommandException("execute fail");
	}));

	cmds->push_back(command0);
	cmds->push_back(command1);
	cmds->push_back(command2);

	MacroCommand macroCommand(cmds);

	ASSERT_THROW(macroCommand.execute(), CommandException);
}

TEST(MacroCommand, MacroFuelCommand_Execute_Success)
{
	double fuel{16.0};
	double velocity{5.0};
	double position{2.4};

	auto cmds = std::make_shared<std::list<std::shared_ptr<ICommand>>>();

	auto object = std::make_shared<MockUObject>();

	auto command0 = std::make_shared<CheckFuelCommand>(object);
	auto command1 = std::make_shared<MoveCommand>(object);
	auto command2 = std::make_shared<BurnFuelCommand>(object);

	EXPECT_CALL(*object, hasProperty("velocity")).WillRepeatedly(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("velocity")).WillRepeatedly(testing::Invoke([velocity]() {
		return std::to_string(velocity);
	}));

	EXPECT_CALL(*object, hasProperty("fuel")).WillRepeatedly(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("fuel")).WillRepeatedly(testing::Invoke([fuel]() {
		return std::to_string(fuel);
	}));

	EXPECT_CALL(*object, hasProperty("position")).WillOnce(testing::Invoke([]() {
		return true;
	}));

	EXPECT_CALL(*object, getProperty("position")).WillOnce(testing::Invoke([position]() {
		return std::to_string(position);
	}));

	cmds->push_back(command0);
	cmds->push_back(command1);
	cmds->push_back(command2);

	MacroCommand macroCommand(cmds);

	macroCommand.execute();
}
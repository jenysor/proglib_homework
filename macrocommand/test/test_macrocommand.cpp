#include "macrocommand.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

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
#include "macrocommand.h"

MacroCommand::MacroCommand(std::shared_ptr<std::list<std::shared_ptr<ICommand>>> cmds) : commands(std::move(cmds))
{}

void MacroCommand::execute()
{
	for(const auto& command: *commands) {
		command->execute();
	}
}

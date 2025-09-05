#include "macrocommand.h"
#include "adapters.h"

MacroCommand::MacroCommand(std::shared_ptr<std::list<std::shared_ptr<ICommand>>> cmds) : commands(std::move(cmds))
{}

void MacroCommand::execute()
{
	for(const auto& command: *commands) {
		command->execute();
	}
}

CorrectInstantVelocityCommand::CorrectInstantVelocityCommand(std::shared_ptr<IUObject> obj) :
    movingObject(std::move(obj))
{}

void CorrectInstantVelocityCommand::execute()
{
	try {
		// VelocityAdapter adapter(movingObject);
		// auto velocity = adapter.getVelocity();
	}
	catch(const std::exception& e) {
		return;
	}
}

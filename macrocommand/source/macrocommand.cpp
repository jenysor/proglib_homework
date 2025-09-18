#include "macrocommand.h"
#include "adapters.h"
#include <cmath>

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
	VelocityAdapter velocityAdapter(movingObject);
	auto velocity = velocityAdapter.getVelocity();

	AngularVelocityAdapter angVelocityAdapter(movingObject);
	auto angVelocity = angVelocityAdapter.getAngularVelocity();

	std::list insVelocity = {velocity * std::cos(angVelocity), -velocity * std::sin(angVelocity)};

	InstantVelocityAdapter insVelocityAdapter(movingObject);
	insVelocityAdapter.setInstantVelocity(insVelocity);
}

#ifndef PROGLIB_HOMEWORK_MACROCOMMAND_H
#define PROGLIB_HOMEWORK_MACROCOMMAND_H

#include "interfaces.h"
#include <list>
#include <memory>

class MacroCommand : public ICommand {
public:
	explicit MacroCommand(std::shared_ptr<std::list<std::shared_ptr<ICommand>>> cmds);

	void execute() override;

private:
	std::shared_ptr<std::list<std::shared_ptr<ICommand>>> commands;
};

class CorrectInstantVelocityCommand : public ICommand {
public:
	explicit CorrectInstantVelocityCommand(std::shared_ptr<IUObject> obj);

	void execute() override;

private:
	std::shared_ptr<IUObject> movingObject;
};

#endif // PROGLIB_HOMEWORK_MACROCOMMAND_H

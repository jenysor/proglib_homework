#ifndef PROGLIB_HOMEWORK_FUELCOMMANDS_H
#define PROGLIB_HOMEWORK_FUELCOMMANDS_H

#include "interfaces.h"
#include <stdexcept>
#include <memory>

class CommandException : public std::runtime_error {
public:
	explicit CommandException(const std::string& msg);
};

class CheckFuelCommand : public ICommand {
public:
	explicit CheckFuelCommand(std::shared_ptr<IUObject> obj);

	void execute() override;

private:
	std::shared_ptr<IUObject> movingObject;
};

class BurnFuelCommand : public ICommand {
public:
	explicit BurnFuelCommand(std::shared_ptr<IUObject> obj);

	void execute() override;

private:
	std::shared_ptr<IUObject> movingObject;
};

#endif // PROGLIB_HOMEWORK_FUELCOMMANDS_H

#include "fuelcommands.h"
#include "adapters.h"

CommandException::CommandException(const std::string& msg) : runtime_error(msg)
{}

CheckFuelCommand::CheckFuelCommand(std::shared_ptr<IUObject> obj) : movingObject(std::move(obj))
{}

void CheckFuelCommand::execute()
{
	VelocityAdapter velocityAdapter(movingObject);
	auto velocity = velocityAdapter.getVelocity();

	FuelAdapter fuelAdapter(movingObject);
	auto fuel = fuelAdapter.getFuel();

	if(fuel < velocity) {
		throw CommandException("not enough fuel");
	}
}

BurnFuelCommand::BurnFuelCommand(std::shared_ptr<IUObject> obj) : movingObject(std::move(obj))
{}

void BurnFuelCommand::execute()
{
	VelocityAdapter velocityAdapter(movingObject);
	auto velocity = velocityAdapter.getVelocity();

	FuelAdapter fuelAdapter(movingObject);
	auto fuel = fuelAdapter.getFuel();

	fuelAdapter.setFuel(fuel - velocity);
}

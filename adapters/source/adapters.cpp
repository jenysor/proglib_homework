#include "adapters.h"
#include <stdexcept>

MovableAdapter::MovableAdapter(std::shared_ptr<IUObject> obj) : object(obj)
{}

double MovableAdapter::getPosition()
{
	if(object->hasProperty("position")) {
		return std::stod(object->getProperty("position"));
	}
	throw std::invalid_argument("can't get position");
}

double MovableAdapter::getVelocity()
{
	if(object->hasProperty("velocity")) {
		return std::stod(object->getProperty("velocity"));
	}
	throw std::invalid_argument("can't get velocity");
}

void MovableAdapter::setPosition(double position)
{
	object->setProperty("position", std::to_string(position));
}

VelocityAdapter::VelocityAdapter(std::shared_ptr<IUObject> obj) : object(obj)
{}

void VelocityAdapter::setVelocity(double velocity)
{
	object->setProperty("velocity", std::to_string(velocity));
}

double VelocityAdapter::getVelocity() const
{
	if(object->hasProperty("velocity")) {
		return std::stod(object->getProperty("velocity"));
	}
	throw std::invalid_argument("can't get velocity");
}

void VelocityAdapter::removeVelocity()
{
	object->removeProperty("velocity");
}

FuelAdapter::FuelAdapter(std::shared_ptr<IUObject> obj) : object(std::move(obj))
{}

double FuelAdapter::getFuel()
{
	if(object->hasProperty("fuel")) {
		return std::stod(object->getProperty("fuel"));
	}
	throw std::invalid_argument("can't get fuel");
}

void FuelAdapter::setFuel(double fuel)
{
	object->setProperty("fuel", std::to_string(fuel));
}

void FuelAdapter::removeFuel()
{
	object->removeProperty("fuel");
}

InstantVelocityAdapter::InstantVelocityAdapter(std::shared_ptr<IUObject> obj) : object(std::move(obj))
{}

void InstantVelocityAdapter::setInstantVelocity(std::list<double> instantVelocity)
{
	if(instantVelocity.size() != 2) {
		throw std::invalid_argument("can't set instant velocity");
	}

	std::string value = std::to_string(instantVelocity.front()) + std::string(", ") + std::to_string(instantVelocity.back());
	object->setProperty("instantVelocity", value);
}

double InstantVelocityAdapter::getInstantVelocity() const
{
	if(object->hasProperty("instantVelocity")) {
		return std::stod(object->getProperty("instantVelocity"));
	}
	throw std::invalid_argument("can't get instant velocity");
}

void InstantVelocityAdapter::removeInstantVelocity()
{
	object->removeProperty("instantVelocity");
}

AngularVelocityAdapter::AngularVelocityAdapter(std::shared_ptr<IUObject> obj) : object(std::move(obj))
{}

void AngularVelocityAdapter::setAngularVelocity(double angularVelocity)
{
	object->setProperty("angularVelocity", std::to_string(angularVelocity));
}

double AngularVelocityAdapter::getAngularVelocity() const
{
	if(object->hasProperty("angularVelocity")) {
		return std::stod(object->getProperty("angularVelocity"));
	}
	throw std::invalid_argument("can't get angular velocity");
}

void AngularVelocityAdapter::removeAngularVelocity()
{
	object->removeProperty("angularVelocity");
}

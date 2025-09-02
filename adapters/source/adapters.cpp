#include "adapters.h"
#include <stdexcept>

MovableAdapter::MovableAdapter(std::shared_ptr<IUObject> obj) : object(obj)
{}

double MovableAdapter::getPosition()
{
	if(object->hasProperty("position")) {
		return std::stoi(object->getProperty("position"));
	}
	throw std::invalid_argument("can't get position");
}

double MovableAdapter::getVelocity()
{
	if(object->hasProperty("velocity")) {
		return std::stoi(object->getProperty("velocity"));
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
		return std::stoi(object->getProperty("velocity"));
	}
	throw std::invalid_argument("can't get velocity");
}

void VelocityAdapter::removeVelocity()
{
	object->removeProperty("velocity");
}

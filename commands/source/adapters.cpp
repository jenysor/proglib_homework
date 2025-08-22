#include "adapters.h"
#include <stdexcept>

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
	else {
		throw std::invalid_argument("can't get velocity");
	}
}

void VelocityAdapter::removeVelocity()
{
	object->removeProperty("velocity");
}

AngularVelocityAdapter::AngularVelocityAdapter(std::shared_ptr<IUObject> obj) : object(obj)
{}

void AngularVelocityAdapter::setAngularVelocity(double angularVelocity)
{
	object->setProperty("angularVelocity", std::to_string(angularVelocity));
}

double AngularVelocityAdapter::getAngularVelocity() const
{
	if(object->hasProperty("angularVelocity")) {
		return std::stoi(object->getProperty("angularVelocity"));
	}
	else {
		throw std::invalid_argument("can't get angular velocity");
	}
}

void AngularVelocityAdapter::removeAngularVelocity()
{
	object->removeProperty("angularVelocity");
}

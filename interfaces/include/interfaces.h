#ifndef PROGLIB_HOMEWORK_INTERFACES_H
#define PROGLIB_HOMEWORK_INTERFACES_H

#include <string>
#include <list>

class IMovable {
public:
	virtual double getPosition() = 0;

	virtual double getVelocity() = 0;

	virtual void setPosition(double position) = 0;

	virtual ~IMovable() = default;
};

class IRotating {
public:
	virtual double getRotation() = 0;

	virtual double getAngularVelocity() = 0;

	virtual void setRotation(double rotation) = 0;

	virtual ~IRotating() = default;
};

class ICommand {
public:
	virtual void execute() = 0;

	virtual ~ICommand() = default;
};

class IUObject {
public:
	virtual void setProperty(const std::string& key, const std::string& value) = 0;

	virtual std::string getProperty(const std::string& key) const = 0;

	virtual bool hasProperty(const std::string& key) const = 0;

	virtual void removeProperty(const std::string& key) = 0;

	virtual ~IUObject() = default;
};

class IVelocityChangeable {
public:
	virtual void setVelocity(double velocity) = 0;

	virtual double getVelocity() const = 0;

	virtual void removeVelocity() = 0;

	virtual ~IVelocityChangeable() = default;
};

class IFuelAdapter {
public:
	virtual double getFuel() = 0;

	virtual void setFuel(double fuel) = 0;

	virtual void removeFuel() = 0;

	virtual ~IFuelAdapter() = default;
};

class IInstantVelocityChangeable {
public:
	virtual void setInstantVelocity(std::list<double> velocity) = 0;

	virtual double getInstantVelocity() const = 0;

	virtual void removeInstantVelocity() = 0;

	virtual ~IInstantVelocityChangeable() = default;
};

class IAngularVelocityChangeable {
public:
	virtual void setAngularVelocity(double velocity) = 0;

	virtual double getAngularVelocity() const = 0;

	virtual void removeAngularVelocity() = 0;

	virtual ~IAngularVelocityChangeable() = default;
};

class IActionAdapter {
public:
	virtual void setAction(const std::string& action) = 0;

	virtual std::string getAction() const = 0;

	virtual void removeAction() = 0;

	virtual ~IActionAdapter() = default;
};

#endif // PROGLIB_HOMEWORK_INTERFACES_H

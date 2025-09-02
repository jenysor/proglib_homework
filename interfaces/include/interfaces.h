#ifndef PROGLIB_HOMEWORK_INTERFACES_H
#define PROGLIB_HOMEWORK_INTERFACES_H

#include <string>

class IMovable
{
public:
	virtual double getPosition() = 0;

	virtual double getVelocity() = 0;

	virtual void setPosition(double position) = 0;

	virtual ~IMovable() = default;
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

// class IPositionChangeable {
// public:
// 	virtual void setPosition(double position) = 0;
//
// 	[[nodiscard]] virtual double getPosition() const = 0;
//
// 	virtual ~IPositionChangeable() = default;
// };
//
class IVelocityChangeable {
public:
	virtual void setVelocity(double velocity) = 0;

	virtual double getVelocity() const = 0;

	virtual void removeVelocity() = 0;

	virtual ~IVelocityChangeable() = default;
};
//
// class IAngularVelocityChangeable {
// public:
// 	virtual void setAngularVelocity(double angularVelocity) = 0;
//
// 	[[nodiscard]] virtual double getAngularVelocity() const = 0;
//
// 	virtual ~IAngularVelocityChangeable() = default;
// };
//
#endif // PROGLIB_HOMEWORK_INTERFACES_H

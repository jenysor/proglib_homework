#ifndef PROGLIB_HOMEWORK_INTERFACES_H
#define PROGLIB_HOMEWORK_INTERFACES_H

#include <string>

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

// Адаптер для изменения скорости
class IVelocityChangeable {
public:
	virtual void setVelocity(double velocity) = 0;

	virtual double getVelocity() const = 0;

	virtual void removeVelocity() = 0;

	virtual ~IVelocityChangeable() = default;
};

// Адаптер для изменения угловой скорости
class IAngularVelocityChangeable {
public:
	virtual void setAngularVelocity(double angularVelocity) = 0;

	virtual double getAngularVelocity() const = 0;

	virtual void removeAngularVelocity() = 0;

	virtual ~IAngularVelocityChangeable() = default;
};

#endif // PROGLIB_HOMEWORK_INTERFACES_H

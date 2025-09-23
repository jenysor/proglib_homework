#ifndef PROGLIB_HOMEWORK_ROTATE_STARTABLE_H
#define PROGLIB_HOMEWORK_ROTATE_STARTABLE_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IRotateCommandStartable {
public:
	[[nodiscard]] virtual std::shared_ptr<IUObject> getRotatingObject() const = 0;

	[[nodiscard]] virtual int getAngularVelocity() const = 0;

	[[nodiscard]] virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

	virtual ~IRotateCommandStartable() = default;
};

class StartRotateCommand : public ICommand {
public:
	explicit StartRotateCommand(std::shared_ptr<IUObject> obj, std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q,
					 double angVelocity);

	void execute() override;

private:
	std::shared_ptr<IUObject> movingObject{};
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue{};
	double angVelocity{0};
};

#endif // PROGLIB_HOMEWORK_ROTATE_STARTABLE_H

#ifndef PROGLIB_HOMEWORK_ROTATE_ENDABLE_H
#define PROGLIB_HOMEWORK_ROTATE_ENDABLE_H

#include "interfaces.h"
#include <memory>
#include <queue>

class IRotateCommandEndable {
public:
	[[nodiscard]] virtual std::shared_ptr<IUObject> getRotatingObject() const = 0;

	[[nodiscard]] virtual std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> getCommandQueue() const = 0;

	virtual ~IRotateCommandEndable() = default;
};

class EndRotateCommand : public ICommand {
public:
	explicit EndRotateCommand(std::shared_ptr<IUObject> obj, std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q);

	void execute() override;

private:
	std::shared_ptr<IUObject> rotatingObject{};
	std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> queue{};
};


#endif // PROGLIB_HOMEWORK_ROTATE_ENDABLE_H

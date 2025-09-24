#ifndef PROGLIB_HOMEWORK_ROTATE_COMMAND_H
#define PROGLIB_HOMEWORK_ROTATE_COMMAND_H

#include "interfaces.h"
#include <memory>

class RotateCommand : public ICommand {
public:
	explicit RotateCommand(std::shared_ptr<IUObject> obj);

	void execute() override;

private:
	std::shared_ptr<IUObject> rotatingObject;
};

#endif //PROGLIB_HOMEWORK_ROTATE_COMMAND_H

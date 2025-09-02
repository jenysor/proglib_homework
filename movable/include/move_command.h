#ifndef PROGLIB_HOMEWORK_MOVE_COMMAND_H
#define PROGLIB_HOMEWORK_MOVE_COMMAND_H

#include "interfaces.h"
#include <memory>

class MoveCommand : public ICommand {
public:
	explicit MoveCommand(std::shared_ptr<IUObject> obj);

	void execute() override;

private:
	std::shared_ptr<IUObject> movingObject{};
};

#endif //PROGLIB_HOMEWORK_MOVE_COMMAND_H

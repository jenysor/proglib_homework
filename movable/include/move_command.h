#ifndef PROGLIB_HOMEWORK_MOVE_COMMAND_H
#define PROGLIB_HOMEWORK_MOVE_COMMAND_H

#include "move_command_interfaces.h"

class MoveCommand : public ICommand {
private:
    std::shared_ptr<VelocityChangeable> movable;

public:
    MoveCommand(std::shared_ptr<VelocityChangeable> mov) : movable(mov) {}

    void execute() override {
        if (movable->getVelocity() != 0) {
//            std::cout << "Moving with velocity: " << movable->getVelocity() << std::endl;
        }
    }
};

#endif //PROGLIB_HOMEWORK_MOVE_COMMAND_H

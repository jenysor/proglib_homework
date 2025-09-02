#include "move_command.h"
#include "movable.h"
#include "adapters.h"

MoveCommand::MoveCommand(std::shared_ptr<IUObject> obj) : movingObject(std::move(obj))
{}

void MoveCommand::execute()
{
	Move::move(std::make_shared<MovableAdapter>(movingObject));
}
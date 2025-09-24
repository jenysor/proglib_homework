#include "rotate_command.h"
#include "rotating.h"
#include "adapters.h"

RotateCommand::RotateCommand(std::shared_ptr<IUObject> obj) : rotatingObject(std::move(obj))
{}

void RotateCommand::execute()
{
	Rotate::rotate(std::make_shared<RotatingAdapter>(rotatingObject));
}

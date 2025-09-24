#include "rotate_startable.h"
#include "adapters.h"
#include "rotate_command.h"

StartRotateCommand::StartRotateCommand(std::shared_ptr<IUObject> obj,
                                       std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q, double angVelocity) :
    movingObject(std::move(obj)), queue(std::move(q)), angVelocity(angVelocity)
{}

void StartRotateCommand::execute()
{
	AngularVelocityAdapter adapter(movingObject);
	adapter.setAngularVelocity(angVelocity);

	queue->push(std::make_shared<RotateCommand>(movingObject));
}

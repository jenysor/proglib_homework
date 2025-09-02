#include "endable.h"
#include "adapters.h"

EndMoveCommand::EndMoveCommand(std::shared_ptr<IUObject> obj,
                               std::shared_ptr<std::queue<std::shared_ptr<ICommand>>> q) :
    movingObject(obj), queue(q)
{}

void EndMoveCommand::execute()
{
	VelocityAdapter adapter(movingObject);
	adapter.removeVelocity();

	//удаление из очереди
}

#include "exception_handler.h"

void ExeptionHandler::registerHandler(std::shared_ptr<IExeptionHandler> handler)
{
    handlers.push_back(handler);
}

void ExeptionHandler::handleExeption(std::shared_ptr<ICommand> cmd, const std::exception &e) {}
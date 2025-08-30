#include "handler_pool.h"

void HandlerPool::registerHandler(std::shared_ptr<IExeptionHandler> handler)
{
    handlers.push_back(handler);
}

void HandlerPool::handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const
{
    for(const auto& h: handlers) {
        if(h->canHandleException(e)) {
            h->handleExeption(cmd, e);
        }
    }
}

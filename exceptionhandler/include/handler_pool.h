#ifndef PROGLIB_HOMEWORK_HANDLER_POOL_H
#define PROGLIB_HOMEWORK_HANDLER_POOL_H

#include "exception_handler.h"
#include <list>
#include <memory>

class HandlerPool {
public:
    void registerHandler(std::shared_ptr<IExeptionHandler> handler);

    void handleExeption(std::shared_ptr<ICommand> cmd, const std::exception& e) const;

    ~HandlerPool() = default;

private:
    std::list<std::shared_ptr<IExeptionHandler>> handlers;
};

#endif //PROGLIB_HOMEWORK_HANDLER_POOL_H
